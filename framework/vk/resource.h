#ifndef VK_RESOURCE_H
#define VK_RESOURCE_H

#include "common.h"
#include "device.h"

namespace framework::vk {

class Resource {
public:
    explicit Resource(std::shared_ptr<Device> device) : device_(std::move(device)) {}
    const std::shared_ptr<Device>& device() const { return device_; }

protected:
    std::shared_ptr<Device> device_;
};

class Buffer : public Resource {
public:
    explicit Buffer(std::shared_ptr<Device> device, VkDeviceSize size, VkBufferUsageFlags usage);
    ~Buffer();

    void update(VkDeviceSize offset, VkDeviceSize length, const void* data);

private:
    VkBuffer vk_buffer_{VK_NULL_HANDLE};
    VkDeviceMemory vk_device_memory_{VK_NULL_HANDLE};
};

class Image : public Resource {
public:
    explicit Image(std::shared_ptr<Device> device);
};

class ImageView : public Resource {
public:
    explicit ImageView(std::shared_ptr<Image> image);

private:
    std::shared_ptr<Image> image_;
};

class FrameBuffer : public Resource {
public:
    FrameBuffer();
};

class ShaderModule : public Resource {
public:
    ShaderModule(std::shared_ptr<Device> device);
};
}  // namespace framework::vk

#endif
