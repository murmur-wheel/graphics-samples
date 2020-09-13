//
// Created by murmur wheel on 2020/9/12.
//

#ifndef FRAMEWORK_UI_PAINTER_H
#define FRAMEWORK_UI_PAINTER_H

#include <cstdint>
#include <vector>

#include "../math/color.h"
#include "../math/vector.h"

namespace framework {

struct RectF {
  float left = 0, top = 0, right = 0, bottom = 0;
};

struct DrawCommandList {
  struct DrawCommand {
    uint32_t first_vertex = 0;
    uint32_t first_index = 0;
    uint32_t index_count = 0;
    uint32_t texture = 0;
  };

  struct Vertex {
    Vec2f pos;  // position
    Vec2f tex;  // texture coordinate
    Vec3f col;  // color
  };

  std::vector<DrawCommand> commands;
  std::vector<Vertex> vertices;
  std::vector<uint16_t> indices;
};

class Painter {
 public:
  void push_clip(const RectF& rect);
  void pop_clip();

  void draw_rectangle(const RectF& rect, const Vec4f& color);
  void fill_rectangle(const RectF& rect, const Vec4f& color,
                      float stroke_width = 1.0f);

  const DrawCommandList& draw_command_list() const {
    return draw_command_list_;
  }

 private:
  DrawCommandList draw_command_list_;
};
}  // namespace framework

#endif  // FRAMEWORK_UI_PAINTER_H
