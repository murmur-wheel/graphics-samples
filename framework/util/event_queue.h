//
// Created by murmur wheel on 2020/9/26.
//

#ifndef FRAMEWORK_UTIL_EVENT_QUEUE_H
#define FRAMEWORK_UTIL_EVENT_QUEUE_H

namespace framework {

namespace detail {}

class EventQueue {
public:
    void add_connection(void* sender, void* signal, void* receiver, void* slot);
    void remove_connection(void* sender, void* signal, void* receiver, void* slot);
    void send(void* sender, void* signal);

    static EventQueue* Get();

private:
};
}  // namespace framework

#endif  // FRAMEWORK_UTIL_EVENT_QUEUE_H
