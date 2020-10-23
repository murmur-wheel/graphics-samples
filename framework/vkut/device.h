//
// Created by murmur-wheel on 2020/9/19.
//

#ifndef FRAMEWORK_VKUT_DEVICE_H
#define FRAMEWORK_VKUT_DEVICE_H

#include "instance.h"

namespace framework {
class VkutDevice {
 public:
  struct Options {};

  VkutDevice() = default;
  ~VkutDevice();

  const VkutInstancePtr& instance() const { return instance_; }
  const VkutDeviceApi& device_api() const { return device_api_; }
  const VkPhysicalDevice& vk_physical_device() const {
    return vk_physical_device_;
  }
  const VkDevice& vk_device() const { return vk_device_; }

  static std::shared_ptr<VkutDevice> Create(VkutInstancePtr instance,
                                            const Options* options);

 private:
  bool init(VkutInstancePtr instance, const Options* options);

  VkutInstancePtr instance_;
  VkutDeviceApi device_api_;

  VkPhysicalDevice vk_physical_device_{VK_NULL_HANDLE};
  VkDevice vk_device_{VK_NULL_HANDLE};
};

using VkutDevicePtr = std::shared_ptr<VkutDevice>;
}  // namespace framework

#endif  // FRAMEWORK_VKUT_DEVICE_H
