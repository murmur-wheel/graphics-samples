//
// Created by murmur wheel on 2020/9/19.
//

#include "vkut_instance.h"

#include <string>
#include <vector>

#include "vkut_tools.h"

namespace framework {
static void prepare_instance_layers(const VkutRegistryApi &api,
                                    const VkutInstance::Options *options,
                                    std::vector<std::string> &layers) {
  uint32_t property_count = 0;
  api.vkEnumerateInstanceLayerProperties(&property_count, nullptr);

  std::vector<VkLayerProperties> layer_properties(property_count);
  api.vkEnumerateInstanceLayerProperties(&property_count,
                                         layer_properties.data());

  if (options && options->debug_enable) {
    const char *debug_layer = "VK_LAYER_LUNARG_standard_validation";
    for (const auto &layer : layer_properties) {
      if (strcmp(debug_layer, layer.layerName) == 0) {
        layers.emplace_back(debug_layer);
        break;
      }
    }
  }
}

static void prepare_instance_extensions(const VkutRegistryApi &api,
                                        const VkutInstance::Options *options,
                                        std::vector<std::string> &extensions) {
  uint32_t property_count = 0;
  api.vkEnumerateInstanceExtensionProperties(nullptr, &property_count, nullptr);

  std::vector<VkExtensionProperties> extension_properties(property_count);
  api.vkEnumerateInstanceExtensionProperties(nullptr, &property_count,
                                             extension_properties.data());
  std::vector<const char *> expected_extensions = {
      VK_KHR_SURFACE_EXTENSION_NAME,
  };
}

static std::vector<const char *> as_c_str(const std::vector<std::string> &l) {
  std::vector<const char *> res;
  res.reserve(l.size());
  for (const auto &t : l) {
    res.push_back(t.c_str());
  }
  return res;
}

VkutInstance::~VkutInstance() {
  if (vk_instance_) {
    instance_api_.vkDestroyInstance(vk_instance_, nullptr);
  }
}

std::vector<VkPhysicalDevice> VkutInstance::enumerate_physical_devices() const {
  uint32_t physical_device_count = 0;
  VKUT_CHECK_RESULT(instance_api_.vkEnumeratePhysicalDevices(
      vk_instance_, &physical_device_count, nullptr));

  std::vector<VkPhysicalDevice> physical_devices(physical_device_count);
  VKUT_CHECK_RESULT(instance_api_.vkEnumeratePhysicalDevices(
      vk_instance_, &physical_device_count, physical_devices.data()));

  return physical_devices;
}

std::shared_ptr<VkutInstance> VkutInstance::Create(const Options *options) {
  auto instance = std::make_shared<VkutInstance>();
  if (!instance->init(options)) {
    return nullptr;
  }
  return instance;
}

bool VkutInstance::init(const Options *options) {
  auto loader = VkutApiLoader::Get();
  vkut_InitRegistryApi(loader->vkGetInstanceProcAddr, &registry_api_);

  std::vector<std::string> enabled_layers;
  std::vector<std::string> enabled_extensions;

  prepare_instance_layers(registry_api_, options, enabled_layers);
  prepare_instance_extensions(registry_api_, options, enabled_extensions);

  std::vector<const char *> layer_c_str = as_c_str(enabled_layers);
  std::vector<const char *> extension_c_str = as_c_str(enabled_extensions);

  VkInstanceCreateInfo instance_create_info = {};
  instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  instance_create_info.enabledLayerCount = layer_c_str.size();
  instance_create_info.ppEnabledLayerNames = layer_c_str.data();
  instance_create_info.enabledExtensionCount = extension_c_str.size();
  instance_create_info.ppEnabledExtensionNames = extension_c_str.data();
  VKUT_CHECK_RESULT(registry_api_.vkCreateInstance(&instance_create_info,
                                                   nullptr, &vk_instance_));

  vkut_InitInstanceApi(vk_instance_, registry_api_.vkGetInstanceProcAddr,
                       &instance_api_);

  return true;
}

}  // namespace framework
