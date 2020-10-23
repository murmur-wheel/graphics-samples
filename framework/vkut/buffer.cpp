//
// Created by murmur-wheel on 2020/9/19.
//

#include "buffer.h"

namespace framework::vkut {
Buffer::Buffer(std::shared_ptr<VkutDevice> device, VkDeviceSize size,
               VkBufferUsageFlags usage_flags,
               VkMemoryPropertyFlags memory_flags)
    : device_(std::move(device)),
      size_(size),
      usage_flags_(usage_flags),
      memory_flags_(memory_flags) {}

Buffer::~Buffer() {
  const auto &api = device_->device_api();
  if (vk_device_memory_) {
    api.vkFreeMemory(device_->vk_device(), vk_device_memory_, nullptr);
  }
  if (vk_buffer_) {
    api.vkDestroyBuffer(device_->vk_device(), vk_buffer_, nullptr);
  }
}

void Buffer::map(VkDeviceSize offset, VkDeviceSize size, void **mapped) {
  const auto &api = device_->device_api();
  VKUT_CHECK_RESULT(api.vkMapMemory(device_->vk_device(), vk_device_memory_,
                                    offset, size, 0, mapped));
}

void Buffer::unmap() {
  const auto &api = device_->device_api();
  api.vkUnmapMemory(device_->vk_device(), vk_device_memory_);
}
}  // namespace framework::vkut
