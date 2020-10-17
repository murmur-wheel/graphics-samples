set(MATH_SOURCE_LIST
        math/color.h
        math/vector.h)

set(UTIL_SOURCE_LIST
        util/event.h
        util/event.cpp
        util/ref_count.h
        util/ref_count.cpp)

set(PLATFORM_SOURCE_LIST
        platform/mouse_event.h
        platform/input.h
        platform/input.cpp
        platform/platform_window.h
        platform/platform.h
        platform/platform.cpp)

set(VKUT_SOURCE_LIST
        vkut/vkut_tools.h
        vkut/vkut_api.h
        vkut/vkut_api.cpp
        vkut/vkut_instance.h
        vkut/vkut_instance.cpp
        vkut/vkut_device.h
        vkut/vkut_device.cpp
        vkut/vkut_swapchain.h
        vkut/vkut_swapchain.cpp
        vkut/vkut_buffer.h
        vkut/vkut_buffer.cpp
        vkut/vkut.h
        vkut/vkut.cpp)

set(UI_SOURCES
        ui/ui_painter.h
        ui/ui_painter.cpp
        ui/ui_widget.h
        ui/ui_widget.cpp
        ui/ui_control.h
        ui/ui_control.cpp)

add_library(framework STATIC
        ${UTIL_SOURCE_LIST}
        ${MATH_SOURCE_LIST}
        ${PLATFORM_SOURCE_LIST}
        ${VKUT_SOURCE_LIST}
        ${UI_SOURCES})
target_link_libraries(framework 3rdparty_stub)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    target_compile_definitions(framework PRIVATE -DVK_USE_PLATFORM_WIN32_KHR)
endif ()

# interface
target_include_directories(framework INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})