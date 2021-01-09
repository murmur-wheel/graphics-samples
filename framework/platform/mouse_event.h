//
// Created by murmur wheel on 2020/9/11.
//

#ifndef FRAMEWORK_INPUT_MOUSE_EVENT_H
#define FRAMEWORK_INPUT_MOUSE_EVENT_H

#include <cstdint>

namespace framework {
enum class MouseEventType {
    undefined,
    down,
    up,
    enter,
    leave,
    out,
    over,
    click,
    db_click,
    aux_click,
};

struct MouseEvent {
    MouseEventType event_type = MouseEventType::undefined;

    const uint32_t PRIMARY_BUTTON = 1;
    const uint32_t SECONDARY_BUTTON = 2;
    const uint32_t AUXILIARY_BUTTON = 4;

    int client_x = 0;
    int client_y = 0;
    int delta_x = 0;
    int delta_y = 0;

    uint32_t buttons = 0;
    uint32_t button = 0;
};

}  // namespace framework

#endif  // FRAMEWORK_INPUT_MOUSE_EVENT_H
