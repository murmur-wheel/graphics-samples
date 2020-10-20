//
// Created by murmur-wheel on 2020/10/20.
//

#ifndef FRAMEWORK_MATH_MATRIX_H
#define FRAMEWORK_MATH_MATRIX_H

#include "vector.h"

namespace framework {
template <typename T>
struct Mat3T {
  T m[3][3];

  Mat3T<T> operator*(const Mat3T<T>& rhs) const {
    Mat3T<T> res;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        res.m[i][j] = 0;
        for (int k = 0; k < 3; ++k) {
          res.m[i][j] += m[i][k] * res.m[k][j];
        }
      }
    }
    return res;
  }

  Vec3T<T> operator*(const Vec3T<T>& rhs) const {
    Vec3T<T> res;
    for (int i = 0; i < 3; ++i) {
      res[i] = 0;
      for (int k = 0; k < 3; ++k) {
        res[i] += m[i][k] * rhs[k];
      }
    }
    return res;
  }
};

template <typename T>
struct Mat4T {
  T m[4][4];

  Mat4T<T> operator*(const Mat4T<T>& rhs) const {
    Mat4T<T> res;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        res.m[i][j] = 0;
        for (int k = 0; k < 4; ++k) {
          res.m[i][j] += m[i][k] * res.m[k][j];
        }
      }
    }
    return res;
  }

  Mat4T<T> operator*(const Vec4T<T>& rhs) const {
    Vec4T<T> res;
    for (int i = 0; i < 4; ++i) {
      res[i] = 0;
      for (int k = 0; k < 4; ++k) {
        res[i] += m[i][k] * rhs[k];
      }
    }
    return res;
  }
};

using Mat3f = Mat3T<float>;
using Mat4f = Mat4T<float>;

}  // namespace framework

#endif  // FRAMEWORK_MATH_MATRIX_H
