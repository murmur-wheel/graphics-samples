//
// Created by murmur wheel on 2020/9/12.
//

#ifndef FRAMEWORK_UI_WIDGET_H
#define FRAMEWORK_UI_WIDGET_H

#include <cstdint>

#include "ui_painter.h"

namespace framework {

class UiWidget {
 public:
  struct Extent {
    uint32_t width = 0;
    uint32_t height = 0;
  };

  struct Rect {
    uint32_t left = 0, top = 0, right = 0, bottom = 0;
  };

  struct MeasureSpec {
    uint32_t width_spec = 0;
    uint32_t height_spec = 0;
  };

  static const uint32_t SPEC_MODE_MASK = 3U << 30U;
  static const uint32_t SPEC_MODE_EXACTLY = 0U << 30U;
  static const uint32_t SPEC_MODE_AT_MOST = 1U << 30U;
  static const uint32_t SPEC_MODE_UNSPECIFIED = 2U << 30U;

  static uint32_t get_spec_mode(uint32_t spec) { return spec & SPEC_MODE_MASK; }
  static uint32_t get_spec_size(uint32_t spec) {
    return spec & (~SPEC_MODE_MASK);
  }
  static uint32_t make_spec(uint32_t mode, uint32_t size) {
    return mode | size;
  }

  virtual void dispatch_mouse_event() = 0;

  virtual Extent measure(const MeasureSpec& spec) = 0;
  virtual void layout(const Rect& region) = 0;
  virtual void draw(UiPainter& painter) = 0;

  void set_event_flag(uint32_t flag) { event_flags_ = event_flags_ | flag; }
  void remove_event_flag(uint32_t flag) {
    event_flags_ = event_flags_ & (~flag);
  }
  bool has_event_flag(uint32_t flag) const { return event_flags_ & flag; }

  void set_bounds(const Rect& bounds) { bounds_ = bounds; }
  const Rect& bounds() const { return bounds_; }

 private:
  uint32_t event_flags_ = 0;
  Rect bounds_;
};
}  // namespace framework

#endif  // FRAMEWORK_UI_WIDGET_H
