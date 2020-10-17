//
// Created by murmur wheel on 2020/9/26.
//

#ifndef FRAMEWORK_UTIL_OBJECT_H
#define FRAMEWORK_UTIL_OBJECT_H

namespace framework {
class EventManager {
 public:
  void add_connection(void* sender, void* signal, void* receiver, void* slot);
  void remove_connection(void* sender, void* signal, void* receiver,
                         void* slot);
  void send(void* sender, void* signal);
  static EventManager* Get();
};
}  // namespace framework

#endif  // FRAMEWORK_UTIL_OBJECT_H
