//
// Created by murmur wheel on 2020/9/19.
//

#ifndef FRAMEWORK_PLATFORM_H
#define FRAMEWORK_PLATFORM_H

namespace framework {

class PlatformWindow {};

class PlatformFactory {
 public:
  static PlatformFactory* Get();
};
}  // namespace framework

#endif  // FRAMEWORK_PLATFORM_H
