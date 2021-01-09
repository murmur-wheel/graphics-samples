//
// Created by murmur wheel on 2020/9/12.
//

#ifndef FRAMEWORK_UI_CONTROL_H
#define FRAMEWORK_UI_CONTROL_H

#include "widget.h"

namespace framework {
class UiControl : public UiWidget {
public:
    virtual void on_click() = 0;
};
}  // namespace framework

#endif  // FRAMEWORK_UI_CONTROL_H
