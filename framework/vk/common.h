#ifndef VK_COMMON_H
#define VK_COMMON_H

#include <vulkan/vulkan.h>

#include <exception>
#include <memory>
#include <stdexcept>

#define VK_CHECK_RESULT(expr)                \
    do {                                     \
        auto ret = (expr);                   \
        if (ret != VkResult::VK_SUCCESS) {   \
            throw std::runtime_error(#expr); \
        }                                    \
    } while (false)

#endif
