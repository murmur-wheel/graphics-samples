//
// Created by murmur wheel on 2020/9/19.
//

#include <math/matrix.h>
#include <math/vector.h>
#include <util/ref_count.h>
#include <vk/api.h>
#include <vk/device.h>

#include <cstdio>

namespace fw = framework;

class MyObject final : public fw::RefCount {
public:
    ~MyObject() override { printf("MyObject::~MyObject()\n"); }
};

int main() {
    fw::vk::init_registry_api();
    for (const auto& layer : fw::vk::Device::enumerate_instance_layers()) {
        printf("%s\n", layer.layerName);
    }
}
