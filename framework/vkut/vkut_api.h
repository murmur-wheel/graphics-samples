//
// Created by murmur wheel on 2020/9/19.
//

#ifndef FRAMEWORK_VK_API_LOADER_H
#define FRAMEWORK_VK_API_LOADER_H

#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>

namespace framework {
// singleton
class VkutApiLoader {
 public:
  VkutApiLoader();
  ~VkutApiLoader();

  static VkutApiLoader* Get();

  PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr{nullptr};

 private:
  void* data_ = nullptr;
};

struct VkutRegistryApi {
  // clang-format off
  PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr{nullptr};
  PFN_vkCreateInstance vkCreateInstance{nullptr};
  PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties{nullptr};
  PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties{nullptr};
  // clang-format on
};

struct VkutInstanceApi {
  PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr{nullptr};
  PFN_vkDestroyInstance vkDestroyInstance{nullptr};
  PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices{nullptr};
  PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr{nullptr};
};

struct VkutSurfaceApi {};

struct VkutDeviceApi {
  PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr{nullptr};
  PFN_vkDestroyDevice vkDestroyDevice{nullptr};
};

struct VkutSwapchainApi {};

void vkut_InitRegistryApi(PFN_vkGetInstanceProcAddr getInstanceProcAddr,
                          VkutRegistryApi* api);
void vkut_InitInstanceApi(VkInstance instance,
                          PFN_vkGetInstanceProcAddr getInstanceProcAddr,
                          VkutInstanceApi* api);
void vkut_InitDeviceApi(VkDevice device,
                        PFN_vkGetDeviceProcAddr getDeviceProcAddr,
                        VkutDeviceApi* api);
}  // namespace framework

#endif  // FRAMEWORK_VK_API_LOADER_H
