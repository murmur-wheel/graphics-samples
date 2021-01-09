#include "api.h"
PFN_vkGetInstanceProcAddr pfn_vkGetInstanceProcAddr{nullptr};

PFN_vkEnumerateInstanceLayerProperties pfn_vkEnumerateInstanceLayerProperties = nullptr;

VkResult vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties) {
    return pfn_vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}

namespace framework::vk {
#ifdef VK_USE_PLATFORM_WIN32_KHR
class Win32Loader {
public:
    Win32Loader() {
        handle_ = LoadLibrary(TEXT("vulkan-1.dll"));
        if (!handle_) {
            throw std::runtime_error("load vulkan-1.dll failed");
        }

        pfn_vkGetInstanceProcAddr =
            reinterpret_cast<PFN_vkGetInstanceProcAddr>(GetProcAddress(handle_, "vkGetInstanceProcAddr"));
    }
    ~Win32Loader() { CloseHandle(handle_); }

private:
    HMODULE handle_{NULL};
};
#endif

void init_api() {
#ifdef VK_USE_PLATFORM_WIN32_KHR
    static Win32Loader win32_loader;
#endif  //

#define BIND_PROC(cmd) pfn_##cmd = reinterpret_cast<PFN_##cmd>(pfn_vkGetInstanceProcAddr(nullptr, #cmd))

    BIND_PROC(vkEnumerateInstanceLayerProperties);
#undef BIND_PROC
}
}  // namespace framework::vk