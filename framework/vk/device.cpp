#include "device.h"

namespace framework::vk {
std::vector<VkLayerProperties> Device::enumerate_instance_layers() {
    uint32_t layer_count = 0;
    VK_CHECK_RESULT(vkEnumerateInstanceLayerProperties(&layer_count, nullptr));

    std::vector<VkLayerProperties> layer_props(layer_count);
    VK_CHECK_RESULT(vkEnumerateInstanceLayerProperties(&layer_count, layer_props.data()));

    return layer_props;
}
}  // namespace framework::vk
