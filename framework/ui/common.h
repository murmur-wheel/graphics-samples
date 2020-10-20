//
// Created by murmur-wheel on 2020/10/20.
//

#ifndef FRAMEWORK_UI_COMMON_H
#define FRAMEWORK_UI_COMMON_H

#include <vector>

#include "../math/color.h"
#include "../math/vector.h"
#include "../util/util.h"

namespace framework {

struct UiExtent {
  int32_t width = 0;
  int32_t height = 0;
};

struct UiRect {
  int32_t left = 0, top = 0, right = 0, bottom = 0;

  UiExtent extent() const {
    UiExtent extent;
    extent.width = right - left;
    extent.height = bottom - top;
    return extent;
  }
};

struct UiRectF {};

}  // namespace framework

#endif  // FRAMEWORK_UI_COMMON_H
