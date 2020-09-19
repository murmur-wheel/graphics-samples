//
// Created by murmur wheel on 2020/9/19.
//

#ifndef FRAMEWORK_VKUT_TOOLS_H
#define FRAMEWORK_VKUT_TOOLS_H

#include <stdexcept>

#include "vkut_api.h"

#define VKUT_CHECK_RESULT(EXPR) \
  do {                          \
    VkResult result = EXPR;     \
    if (result != VK_SUCCESS) { \
      std::abort();             \
    }                           \
  } while (false)

#endif  // FRAMEWORK_VKUT_TOOLS_H
