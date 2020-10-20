set(MATH_SOURCE_LIST
        math/color.h
        math/vector.h)
source_group(math FILES ${MATH_SOURCE_LIST})

set(UTIL_SOURCE_LIST
        util/common.h
        util/wait_group.h
        util/ref_count.h
        util/event_queue.h
        util/event_queue.cpp
        util/util.h)
source_group(util FILES ${UTIL_SOURCE_LIST})

set(PLATFORM_SOURCE_LIST
        platform/mouse_event.h
        platform/input.h
        platform/input.cpp
        platform/platform_window.h
        platform/platform.h
        platform/platform.cpp)
source_group(platform FILES ${PLATFORM_SOURCE_LIST})

set(VKUT_SOURCE_LIST
        vkut/common.h
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
source_group(vkut FILES ${VKUT_SOURCE_LIST})

set(UI_SOURCES
        ui/common.h
        ui/ui_painter.h
        ui/ui_painter.cpp
        ui/ui_widget.h
        ui/ui_widget.cpp
        ui/ui_control.h
        ui/ui_control.cpp)
source_group(ui FILES ${UI_SOURCES})

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