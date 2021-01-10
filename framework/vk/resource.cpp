#include "resource.h"

namespace framework::vk {
Buffer::Buffer(std::shared_ptr<Device> device, VkDeviceSize size, VkBufferUsageFlags usage)
    : Resource(std::move(device)) {
    VkBufferCreateInfo buffer_create_info = {};
    buffer_create_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_create_info.size = size;
    buffer_create_info.usage = usage;
    VK_CHECK_RESULT(vkCreateBuffer(device_->vk_device(), &buffer_create_info, nullptr, &vk_buffer_));

    VkMemoryRequirements memory_requirements;
    vkGetBufferMemoryRequirements(device_->vk_device(), vk_buffer_, &memory_requirements);
}

Buffer::~Buffer() {
    if (vk_device_memory_) {
        vkFreeMemory(device_->vk_device(), vk_device_memory_, nullptr);
    }
    if (vk_buffer_) {
        vkDestroyBuffer(device_->vk_device(), vk_buffer_, nullptr);
    }
}
}  // namespace framework::vk
