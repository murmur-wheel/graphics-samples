//
// Created by murmur wheel 2020/9/19.
//

#ifndef FRAMEWORK_VKUT_H
#define FRAMEWORK_VKUT_H

#include "api.h"
#include "buffer.h"
#include "common.h"
#include "device.h"
#include "instance.h"
#include "swapchain.h"


namespace framework {
void vkut_CreateDeviceAndSwapchain(const VkutInstancePtr& instance,
                                   VkSurfaceKHR surface,
                                   VkutDevicePtr* out_device,
                                   VkutSwapchainPtr* out_swapchain);
}  // namespace framework

#endif  // FRAMEWORK_VKUT_H
