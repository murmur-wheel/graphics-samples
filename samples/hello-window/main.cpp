//
// Created by murmu on 2020/9/19.
//

#include <vkut/vkut_api.h>
#include <vkut/vkut_device.h>
#include <vkut/vkut_instance.h>

#include <cstdio>

int main() {
  auto instance = framework::VkutInstance::Create(nullptr);
  auto device = framework::VkutDevice::Create(instance, nullptr);
  device->device_api().vkDestroyDevice(nullptr, nullptr);
}
