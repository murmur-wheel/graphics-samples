//
// Created by murmur-wheel on 2020/9/19.
//

#include "api.h"

namespace framework {
#ifdef VK_USE_PLATFORM_WIN32_KHR
struct VkutWin32LibraryData {
  HMODULE library_module{nullptr};
  PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr{nullptr};
  VkutWin32LibraryData() {
    // clang-format off
            library_module = LoadLibrary(TEXT("vulkan-1.dll"));
            vkGetInstanceProcAddr = reinterpret_cast<PFN_vkGetInstanceProcAddr>(GetProcAddress(library_module, "vkGetInstanceProcAddr"));
    // clang-format on
  }
  ~VkutWin32LibraryData() { FreeLibrary(library_module); }
};
using VkutLibraryData = VkutWin32LibraryData;
#endif

VkutApiLibrary::VkutApiLibrary() {
  data_ = new VkutLibraryData;
  auto* ptr = static_cast<VkutLibraryData*>(data_);
  vkGetInstanceProcAddr = ptr->vkGetInstanceProcAddr;
}

VkutApiLibrary::~VkutApiLibrary() {
  delete static_cast<VkutLibraryData*>(data_);
}

VkutApiLibrary* VkutApiLibrary::Get() {
  static VkutApiLibrary loader;
  return &loader;
}

void vkut_InitRegistryApi(PFN_vkGetInstanceProcAddr getInstanceProcAddr,
                          VkutRegistryApi* api) {
  api->vkGetInstanceProcAddr = getInstanceProcAddr;

#define BIND_PROC(NAME) \
  api->NAME = reinterpret_cast<PFN_##NAME>(getInstanceProcAddr(nullptr, #NAME))
  BIND_PROC(vkEnumerateInstanceExtensionProperties);
  BIND_PROC(vkEnumerateInstanceLayerProperties);
  BIND_PROC(vkCreateInstance);
#undef BIND_PROC
}

void vkut_InitInstanceApi(VkInstance instance,
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

void vkut_InitDeviceApi(VkDevice device,
                        PFN_vkGetDeviceProcAddr getDeviceProcAddr,
                        VkutDeviceApi* api) {
  api->vkGetDeviceProcAddr = getDeviceProcAddr;

#define BIND_PROC(NAME) \
  api->NAME = reinterpret_cast<PFN_##NAME>(getDeviceProcAddr(device, #NAME))

  BIND_PROC(vkDestroyDevice);

  BIND_PROC(vkCreateBuffer);
  BIND_PROC(vkDestroyBuffer);

  BIND_PROC(vkFreeMemory);
  BIND_PROC(vkMapMemory);
  BIND_PROC(vkUnmapMemory);
#undef BIND_PROC
}

}  // namespace framework
