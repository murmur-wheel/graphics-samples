//
// Created by murmur wheel on 2020/9/12.
//

#ifndef FRAMEWORK_UI_WIDGET_H
#define FRAMEWORK_UI_WIDGET_H

#include <cstdint>

#include "common.h"
#include "ui_painter.h"

namespace framework {

static const uint32_t UI_SPEC_MODE_MASK = 3U << 30U;
static const uint32_t UI_SPEC_MODE_EXACTLY = 0U << 30U;
static const uint32_t UI_SPEC_MODE_AT_MOST = 1U << 30U;
static const uint32_t UI_SPEC_MODE_UNSPECIFIED = 2U << 30U;

inline uint32_t ui_get_spec_mode(uint32_t spec) {
  return spec & UI_SPEC_MODE_MASK;
}
inline uint32_t ui_get_spec_size(uint32_t spec) {
  return spec & ~UI_SPEC_MODE_MASK;
}
inline uint32_t ui_make_spec(uint32_t mode, uint32_t size) {
  return mode | size;
}

struct UiWidgetSpec {
  uint32_t width_spec = 0;
  uint32_t height_spec = 0;
};

class UiWidget {
 public:
  static const uint32_t UI_FLAG_DIRTY = 1 << 0U;
  static const uint32_t UI_FLAG_MOUSE_OVER = 1 << 1U;
  static const uint32_t UI_FLAG_MOUSE_LEAVE = 1 << 2U;

  UiWidget() = default;
  virtual ~UiWidget() = default;

  virtual UiExtent measure(const UiWidgetSpec& spec) = 0;
  virtual void layout(const UiRect& region) = 0;
  virtual void draw(UiPainter& painter) = 0;

  void set_flag(uint32_t flag) { flags_ = flags_ | flag; }
  void remove_flag(uint32_t flag) { flags_ = flags_ & (~flag); }
  bool is_flag(uint32_t flag) const { return flags_ & flag; }

  void set_bounds(const UiRect& bounds) { bounds_ = bounds; }
  const UiRect& bounds() const { return bounds_; }

 private:
  uint32_t flags_ = 0;
  UiRect bounds_;

  DISABLE_COPY_AND_MOVE(UiWidget)
};

}  // namespace framework

#endif  // FRAMEWORK_UI_WIDGET_H
