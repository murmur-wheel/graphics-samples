//
// Created by murmur wheel on 2020/9/19.
//

#include "platform.h"

namespace framework {
PlatformFactory* PlatformFactory::Get() {
    static PlatformFactory factory;
    return &factory;
}
}  // namespace framework
