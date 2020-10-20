//
// Created by murmur wheel on 2020/9/13.
//

#ifndef FRAMEWORK_MATH_VECTOR_H
#define FRAMEWORK_MATH_VECTOR_H

namespace framework {

template <typename T>
struct Vec2T {
  T x = 0, y = 0;

  Vec2T() = default;
  explicit Vec2T(T x, T y) : x(x), y(y) {}
};

template <typename T>
struct Vec3T {
  T x = 0, y = 0, z = 0;

  Vec3T() = default;
  explicit Vec3T(T x, T y, T z) : x(x), y(y), z(z) {}
};

template <typename T>
struct Vec4T {
  T x = 0, y = 0, z = 0, w = 0;
  Vec4T() = default;
  explicit Vec4T(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}
};

using Vec2f = Vec2T<float>;
using Vec3f = Vec3T<float>;
using Vec4f = Vec4T<float>;
}  // namespace framework

#endif  // FRAMEWORK_MATH_VECTOR_H
