//
// Created by murmur wheel on 2020/9/19.
//

#include "vkut_instance.h"

#include <string>
#include <vector>

namespace framework {
static VkutInstance::Options* get_default_options() {
  static VkutInstance::Options options;
  options.enabled_layers.emplace_back("");
  return &options;
}

static bool validate_instance_layers(const VkutRegistryApi& api,
                                     const std::vector<std::string>& layers) {
  return true;
}

static bool validate_instance_extensions(
    const VkutRegistryApi& api, const std::vector<std::string>& extensions) {
  return true;
}

static std::vector<const char*> as_c_str(const std::vector<std::string>& l) {
  std::vector<const char*> res;
  res.reserve(l.size());
  for (const auto& t : l) {
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

std::shared_ptr<VkutInstance> VkutInstance::Create(const Options* options) {
  auto instance = std::make_shared<VkutInstance>();
  if (!instance->init(options)) {
    return nullptr;
  }
  return instance;
}

bool VkutInstance::init(const Options* options) {
  if (!options) {
    options = get_default_options();
  }

  auto* loader = VkutApiLibrary::Get();
  vkut_InitRegistryApi(loader->vkGetInstanceProcAddr, &registry_api_);

  if (!validate_instance_layers(registry_api_, options->enabled_layers) ||
      !validate_instance_extensions(registry_api_,
                                    options->enabled_extensions)) {
    return false;
  }

  std::vector<const char*> layer_c_str = as_c_str(options->enabled_layers);
  std::vector<const char*> extension_c_str =
      as_c_str(options->enabled_extensions);

  VkInstanceCreateInfo instance_create_info = {};
  // clang-format off
  instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  instance_create_info.enabledLayerCount = static_cast<uint32_t>(layer_c_str.size());
  instance_create_info.ppEnabledLayerNames = layer_c_str.data();
  instance_create_info.enabledExtensionCount = static_cast<uint32_t>(extension_c_str.size());
  instance_create_info.ppEnabledExtensionNames = extension_c_str.data();
  // clang-format on
  VKUT_CHECK_RESULT(registry_api_.vkCreateInstance(&instance_create_info,
                                                   nullptr, &vk_instance_));

  vkut_InitInstanceApi(vk_instance_, registry_api_.vkGetInstanceProcAddr,
                       &instance_api_);

  return true;
}

}  // namespace framework
