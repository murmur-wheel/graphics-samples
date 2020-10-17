//
// Created by murmur wheel on 2020/9/12.
//

#ifndef FRAMEWORK_UI_WIDGET_H
#define FRAMEWORK_UI_WIDGET_H

#include <cstdint>

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
  return spec & (~UI_SPEC_MODE_MASK);
}
inline uint32_t ui_make_spec(uint32_t mode, uint32_t size) {
  return mode | size;
}

struct UiExtent {
  uint32_t width = 0;
  uint32_t height = 0;
};

struct UiRect {
  uint32_t left = 0, top = 0, right = 0, bottom = 0;
};

struct UiWidgetSpec {
  uint32_t width_spec = 0;
  uint32_t height_spec = 0;
};

class UiWidget {
 public:
  virtual UiExtent measure(const UiWidgetSpec& spec) = 0;
  virtual void layout(const UiRect& region) = 0;
  virtual void draw(UiPainter& painter) = 0;

  void set_event_flag(uint32_t flag) { event_flags_ = event_flags_ | flag; }
  void remove_event_flag(uint32_t flag) {
    event_flags_ = event_flags_ & (~flag);
  }
  bool has_event_flag(uint32_t flag) const { return event_flags_ & flag; }

  void set_bounds(const UiRect& bounds) { bounds_ = bounds; }
  const UiRect& bounds() const { return bounds_; }

 private:
  uint32_t event_flags_ = 0;
  UiRect bounds_;
};

void ui_dispatch_mouse_event(UiWidget* widget);
void ui_dispatch_keyboard_event(UiWidget* widget);

}  // namespace framework

#endif  // FRAMEWORK_UI_WIDGET_H
