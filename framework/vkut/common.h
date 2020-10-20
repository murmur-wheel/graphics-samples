//
// Created by murmur-wheel on 2020/10/18.
//

#ifndef FRAMEWORK_VKUT_COMMON_H
#define FRAMEWORK_VKUT_COMMON_H

#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>

#define VKUT_CHECK_RESULT(EXPR) \
  do {                          \
    VkResult result = EXPR;     \
    if (result != VK_SUCCESS) { \
      std::abort();             \
    }                           \
  } while (false)

#endif
