//
// Created by murmur-wheel on 2020/9/19.
//

#ifndef FRAMEWORK_VKUT_BUFFER_H
#define FRAMEWORK_VKUT_BUFFER_H

#include "device.h"

namespace framework::vkut {
class Buffer {
 public:
  explicit Buffer(std::shared_ptr<VkutDevice> device, VkDeviceSize size,
                  VkBufferUsageFlags usage_flags,
                  VkMemoryPropertyFlags memory_flags);
  ~Buffer();

  VkDeviceSize size() const { return size_; }
  const VkBuffer& vk_buffer() const { return vk_buffer_; }
  const VkDeviceMemory& vk_device_memory() const { return vk_device_memory_; }

  void map(VkDeviceSize offset, VkDeviceSize size, void** mapped);
  void unmap();

  static std::shared_ptr<Buffer> create(std::shared_ptr<VkutDevice> device,
                                        VkDeviceSize size,
                                        VkBufferUsageFlags usage_flags,
                                        VkMemoryPropertyFlags memory_flags) {
    return std::make_shared<Buffer>(std::move(device), size, usage_flags,
                                    memory_flags);
  }

 private:
  std::shared_ptr<VkutDevice> device_;

  VkBuffer vk_buffer_{VK_NULL_HANDLE};
  VkDeviceMemory vk_device_memory_{VK_NULL_HANDLE};

  VkDeviceSize size_{0};
  VkBufferUsageFlags usage_flags_{0};
  VkMemoryPropertyFlags memory_flags_{0};
};
}  // namespace framework::vkut

#endif  // FRAMEWORK_VKUT_BUFFER_H
