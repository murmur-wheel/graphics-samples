//
// Created by murmur wheel 2020/9/19.
//

#ifndef FRAMEWORK_VKUT_H
#define FRAMEWORK_VKUT_H

#include "vkut_api.h"
#include "vkut_buffer.h"
#include "vkut_device.h"
#include "vkut_instance.h"
#include "vkut_swapchain.h"
#include "vkut_tools.h"

namespace framework {
void vkut_CreateDeviceAndSwapchain(const VkutInstancePtr& instance,
                                   VkSurfaceKHR surface,
                                   VkutDevicePtr* out_device,
                                   VkutSwapchainPtr* out_swapchain);
}  // namespace framework

#endif  // FRAMEWORK_VKUT_H
