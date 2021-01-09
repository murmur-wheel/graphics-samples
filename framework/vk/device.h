#ifndef VK_DEVICE_H
#define VK_DEVICE_H

#include "common.h"

namespace framework::vk {
class Device {
public:
    const VkDevice& vk_device() const { return vk_device_; }

    static std::vector<VkLayerProperties> enumerate_instance_layers();

private:
    VkDevice vk_device_{VK_NULL_HANDLE};
};
};  // namespace framework::vk

#endif
