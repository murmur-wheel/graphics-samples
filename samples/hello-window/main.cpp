//
// Created by murmur wheel on 2020/9/19.
//

#include <math/matrix.h>
#include <math/vector.h>
#include <util/ref_count.h>
#include <vkut/vkut_device.h>

#include <cstdio>

namespace fw = framework;

class MyObject final : public fw::RefCount {
 public:
  ~MyObject() override { printf("MyObject::~MyObject()\n"); }
};

int main() {
  const framework::Vec2f v2f(1, 2);
  const auto sum2f = v2f + v2f;
  printf("sum = [%f, %f]\n", sum2f.x, sum2f.y);

  framework::Mat3f m3f;
}
