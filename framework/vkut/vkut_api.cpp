//
// Created by murmur wheel on 2020/9/19.
//

#include "vkut_api.h"

namespace framework {

struct VkutLibraryLoaderData {
  PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr{nullptr};

  // windows platform
#ifdef VK_USE_PLATFORM_WIN32_KHR
  HMODULE library_module{nullptr};

  VkutLibraryLoaderData() {
    // clang-format off
    library_module = LoadLibrary(TEXT("vulkan-1.dll"));
    vkGetInstanceProcAddr = reinterpret_cast<PFN_vkGetInstanceProcAddr>(GetProcAddress(library_module, "vkGetInstanceProcAddr"));
    // clang-format on
  }

  ~VkutLibraryLoaderData() { FreeLibrary(library_module); }
#endif

  // TODO: android

  // TODO: linux
};

VkutApiLoader::VkutApiLoader() {
  data_ = new VkutLibraryLoaderData;
  auto ptr = reinterpret_cast<VkutLibraryLoaderData*>(data_);
  vkGetInstanceProcAddr = ptr->vkGetInstanceProcAddr;
}

VkutApiLoader::~VkutApiLoader() {
  delete reinterpret_cast<VkutLibraryLoaderData*>(data_);
}

VkutApiLoader* VkutApiLoader::Get() {
  static VkutApiLoader loader;
  return &loader;
}

void vkut_init_RegisteryApi(PFN_vkGetInstanceProcAddr getInstanceProcAddr,
                            VkutRegistryApi* api) {
  api->vkGetInstanceProcAddr = getInstanceProcAddr;

#define BIND_PROC(NAME) \
  api->NAME = reinterpret_cast<PFN_##NAME>(getInstanceProcAddr(nullptr, #NAME))
  BIND_PROC(vkEnumerateInstanceExtensionProperties);
  BIND_PROC(vkEnumerateInstanceLayerProperties);
  BIND_PROC(vkCreateInstance);
#undef BIND_PROC
}

void vkut_init_InstanceApi(VkInstance instance,
                           PFN_vkGetInstanceProcAddr getInstanceProcAddr,
                           VkutInstanceApi* api) {
  api->vkGetInstanceProcAddr = getInstanceProcAddr;

#define BIND_PROC(NAME) \
  api->NAME = reinterpret_cast<PFN_##NAME>(getInstanceProcAddr(instance, #NAME))

  BIND_PROC(vkDestroyInstance);
  BIND_PROC(vkEnumeratePhysicalDevices);
  BIND_PROC(vkGetDeviceProcAddr);
#undef BIND_PROC
}

void vkut_init_DeviceApi(VkDevice device,
                         PFN_vkGetDeviceProcAddr getDeviceProcAddr,
                         VkutDeviceApi* api) {
  api->vkGetDeviceProcAddr = getDeviceProcAddr;

#define BIND_PROC(NAME) \
  api->NAME = reinterpret_cast<PFN_##NAME>(getDeviceProcAddr(device, #NAME))

  BIND_PROC(vkDestroyDevice);
#undef BIND_PROC
}

}  // namespace framework
