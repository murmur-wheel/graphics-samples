//
// Created by murmur wheel on 2020/9/19.
//

#include <util/ref_count.h>
#include <vkut/vkut_device.h>

#include <cstdio>

namespace fw = framework;

class MyObject final : public fw::RefCount {
 public:
  ~MyObject() override { printf("MyObject::~MyObject()\n"); }
};

int main() {
  const auto dx = [](MyObject* obj) { delete obj; };

  fw::RefPtr<MyObject, decltype(dx)> ptr(new MyObject, dx);

  ptr->add_ref();
  ptr->sub_ref();
}
