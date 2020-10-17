//
// Created by murmur wheel on 2020/9/26.
//

#include "event.h"

namespace framework {

void example() {
  auto mgr = EventManager::Get();
  mgr->send(nullptr, nullptr);
}

}  // namespace framework
