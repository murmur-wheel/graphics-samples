#ifndef VK_DEVICE_H
#define VK_DEVICE_H

#include "common.h"

namespace framework::vk {
class Device {
public:
    explicit Device(const std::vector<std::string>& instance_layers,
                    const std::vector<std::string>& instance_extensions,
                    const std::vector<std::string>& device_extensions);
    ~Device();
    const VkInstance& vk_instance() const { return vk_instance_; }
    const VkDevice& vk_device() const { return vk_device_; }

    uint32_t find_memory_type(uint32_t type_bits, VkMemoryPropertyFlags memory_property_flags) const;

    static std::vector<VkLayerProperties> enumerate_instance_layers();

private:
    VkInstance vk_instance_{VK_NULL_HANDLE};
    VkDevice vk_device_{VK_NULL_HANDLE};
};
};  // namespace framework::vk

#endif
