//
// Created by murmur wheel on 2020/9/11.
//

#ifndef FRAMEWORK_INPUT_H
#define FRAMEWORK_INPUT_H

#include "mouse_event.h"

namespace framework {
struct InputHandler {
    virtual bool contains(uint32_t pt_x, uint32_t pt_y) = 0;
    virtual void dispatch_mouse_event(const MouseEvent* mouse_event) = 0;
};

void dispatch_mouse_event(const MouseEvent* mouse_event, InputHandler* handler);
}  // namespace framework

#endif  // FRAMEWORK_INPUT_H
