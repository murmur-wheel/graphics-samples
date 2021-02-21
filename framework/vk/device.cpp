#include "device.h"

namespace framework::vk {
Device::Device(const std::vector<std::string>& instance_layers, const std::vector<std::string>& instance_extensions,
               const std::vector<std::string>& device_extensions) {
    std::vector<const char*> instance_layers_c;
    for (const auto& layer : instance_layers) {
        instance_layers_c.push_back(layer.c_str());
    }
    std::vector<const char*> instance_extensions_c;
    for (const auto& ext : instance_extensions) {
        instance_extensions_c.push_back(ext.c_str());
    }

    VkInstanceCreateInfo instance_create_info = {
        VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        nullptr,
        0,
        nullptr,
        static_cast<uint32_t>(instance_layers_c.size()),
        instance_layers_c.data(),
        static_cast<uint32_t>(instance_extensions_c.size()),
        instance_extensions_c.data(),
    };
    VK_CHECK_RESULT(vkCreateInstance(&instance_create_info, nullptr, &vk_instance_));
}

Device::~Device() {
    if (vk_device_) {
        vkDestroyDevice(vk_device_, nullptr);
    }
    if (vk_instance_) {
        vkDestroyInstance(vk_instance_, nullptr);
    }
}

std::vector<VkLayerProperties> Device::enumerate_instance_layers() {
    uint32_t layer_count = 0;
    VK_CHECK_RESULT(vkEnumerateInstanceLayerProperties(&layer_count, nullptr));

    std::vector<VkLayerProperties> layer_props(layer_count);
    VK_CHECK_RESULT(vkEnumerateInstanceLayerProperties(&layer_count, layer_props.data()));

    return layer_props;
}
}  // namespace framework::vk
