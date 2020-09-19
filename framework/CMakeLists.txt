set(INPUT_SOURCES
        input/mouse_event.h
        input/input.h
        input/input.cpp)

set(MATH_SOURCE_LIST
        math/color.h
        math/vector.h
        )

set(VKUT_SOURCE_LIST
        vkut/vkut_tools.h
        vkut/vkut_api.h
        vkut/vkut_api.cpp
        vkut/vkut_instance.h
        vkut/vkut_instance.cpp
        vkut/vkut_device.h
        vkut/vkut_device.cpp
        vkut/vkut_buffer.h
        vkut/vkut_buffer.cpp
        vkut/vkut.h)

set(UI_SOURCES
        ui/ui_painter.h
        ui/ui_painter.cpp
        ui/ui_widget.h
        ui/ui_widget.cpp
        ui/ui_control.h
        ui/ui_control.cpp)

add_library(framework STATIC ${VKUT_SOURCE_LIST} ${INPUT_SOURCES} ${UI_SOURCES})
target_link_libraries(framework 3rdparty_stub)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    target_compile_definitions(framework PRIVATE -DVK_USE_PLATFORM_WIN32_KHR)
endif ()

# interface
target_include_directories(framework INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})