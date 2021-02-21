#ifndef VK_API_H
#define VK_API_H

#include "common.h"

namespace framework::vk {
void init_registry_api();
void init_instance_api(VkInstance instance);
void init_device_api(VkDevice device);
}  // namespace framework::vk

#endif
