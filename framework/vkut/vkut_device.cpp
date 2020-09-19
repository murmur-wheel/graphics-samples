//
// Created by murmur wheel on 2020/9/19.
//

#include "vkut_device.h"

namespace framework {
VkutDevice::~VkutDevice() {
  if (vk_device_) {
    device_api_.vkDestroyDevice(vk_device_, nullptr);
  }
}

std::shared_ptr<VkutDevice> VkutDevice::Create(VkutInstancePtr instance,
                                               const Options *options) {
  auto device = std::make_shared<VkutDevice>();
  if (!device->init(std::move(instance), options)) {
    return nullptr;
  }
  return device;
}

bool VkutDevice::init(VkutInstancePtr instance, const Options *options) {
  instance_ = std::move(instance);

  auto physical_devices = instance_->enumerate_physical_devices();

  vkut_InitDeviceApi(vk_device_, instance_->instance_api().vkGetDeviceProcAddr,
                     &device_api_);

  return true;
}
}  // namespace framework
