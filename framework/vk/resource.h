#ifndef VK_RESOURCE_H
#define VK_RESOURCE_H

#include "common.h"
#include "device.h"

namespace framework::vk {
class Buffer {
public:
    explicit Buffer(std::shared_ptr<Device> device, VkDeviceSize size, VkBufferUsageFlags usage);
    ~Buffer();

    void update(VkDeviceSize offset, VkDeviceSize length, const void* data);

private:
    std::shared_ptr<Device> device_;
    VkBuffer vk_buffer_{VK_NULL_HANDLE};
    VkDeviceMemory vk_device_memory_{VK_NULL_HANDLE};
};

class Image {};

class ImageView {};

class FrameBuffer {};

class ShaderModule {};
}  // namespace framework::vk

#endif
