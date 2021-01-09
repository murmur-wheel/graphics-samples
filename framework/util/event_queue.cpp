//
// Created by murmur wheel on 2020/9/26.
//

#include "event_queue.h"

namespace framework {

void example() {
    auto mgr = EventQueue::Get();
    mgr->send(nullptr, nullptr);
}

}  // namespace framework
