//
// Created by murmur wheel on 2020/9/19.
//

#ifndef FRAMEWORK_PLATFORM_WINDOW_H
#define FRAMEWORK_PLATFORM_WINDOW_H

#include "../vkut/vkut.h"

namespace framework {
class PlatformWindow {
public:
    virtual void create_vk_surface() = 0;
};
}  // namespace framework

#endif  // FRAMEWORK_PLATFORM_WINDOW_H
