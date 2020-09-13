set(INPUT_SOURCES
        input/mouse_event.h
        input/input.h
        input/input.cpp)

set(MATH_SOURCE_LIST
        math/color.h
        math/vector.h
        )

set(UI_SOURCES
        ui/painter.h
        ui/painter.cpp
        ui/widget.h
        ui/widget.cpp
        ui/control.h
        ui/control.cpp)

add_library(framework STATIC ${INPUT_SOURCES} ${UI_SOURCES})