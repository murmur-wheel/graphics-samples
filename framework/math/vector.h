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
  explicit Vec2T(T _x, T _y) : x(_x), y(_y) {}

  Vec2T<T> operator+(const Vec2T<T>& rhs) const {
    return Vec2T(x + rhs.x, y + rhs.y);
  }
  Vec2T<T>& operator+=(const Vec2T<T>& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  Vec2T<T> operator-(const Vec2T<T>& rhs) const {
    return Vec2T(x - rhs.x, y - rhs.y);
  }
  Vec2T<T>& operator-=(const Vec2T<T>& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  Vec2T<T> operator*(const Vec2T<T>& rhs) const {
    return Vec2T<T>(x * rhs.x, y * rhs.y);
  }
  Vec2T<T>& operator*=(const Vec2T<T>& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
  }
};

template <typename T>
struct Vec3T {
  T x = 0, y = 0, z = 0;

  Vec3T() = default;
  explicit Vec3T(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
  explicit Vec3T(const Vec2T<T>& v, T _z) : x(v.x), y(v.y), z(_z) {}

  Vec3T<T> operator+(const Vec3T<T>& rhs) const {
    return Vec3T<T>(x + rhs.x, y + rhs.y, z + rhs.z);
  }
  Vec3T<T>& operator+=(const Vec3T<T>& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }

  Vec3T<T> operator-(const Vec3T<T>& rhs) const {
    return Vec3T<T>(x - rhs.x, y - rhs.y, z - rhs.z);
  }
  Vec3T<T>& operator-=(const Vec3T<T>& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }
};

template <typename T>
struct Vec4T {
  T x = 0, y = 0, z = 0, w = 0;
  Vec4T() = default;
  explicit Vec4T(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}

  Vec4T<T> operator+(const Vec4T<T>& rhs) const {
    return Vec4T<T>(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
  }
  Vec4T<T>& operator+=(const Vec4T<T>& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;
    return *this;
  }

  Vec4T<T> operator-(const Vec4T<T>& rhs) const {
    return Vec4T<T>(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
  }
  Vec4T<T>& operator-=(const Vec4T<T>& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;
    return *this;
  }
};

// dot
template <typename T>
T dot(const Vec2T<T>& v1, const Vec2T<T>& v2) {
  return v1.x * v2.x + v1.y * v2.y;
}

template <typename T>
T dot(const Vec3T<T>& v1, const Vec3T<T>& v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template <typename T>
T dot(const Vec4T<T>& v1, const Vec4T<T>& v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

// cross
template <typename T>
Vec3T<T> cross(const Vec3T<T>& v1, const Vec3T<T>& v2) {
  T x = v1.y * v2.z - v1.z * v2.y;
  T y = v1.z * v2.x - v1.x * v2.z;
  T z = v1.x * v2.y - v1.y * v2.x;
  return Vec3T<T>(x, y, z);
}

using Vec2f = Vec2T<float>;
using Vec3f = Vec3T<float>;
using Vec4f = Vec4T<float>;
}  // namespace framework

#endif  // FRAMEWORK_MATH_VECTOR_H
