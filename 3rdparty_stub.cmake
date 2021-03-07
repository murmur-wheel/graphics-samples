add_library(3rdparty_stub INTERFACE)

include(FetchContent)

# gflags
FetchContent_Declare(
    gflags
    URL https://github.com/gflags/gflags/archive/v2.2.2.zip
)
FetchContent_GetProperties(gflags)
if (NOT gflags_POPULATED)
    FetchContent_Populate(gflags)
    add_subdirectory(${gflags_SOURCE_DIR} ${gflags_BINARY_DIR})
    target_link_libraries(3rdparty_stub INTERFACE gflags::gflags)
endif ()

# glog
FetchContent_Declare(
    glog
    URL https://github.com/google/glog/archive/v0.4.0.zip
)
FetchContent_GetProperties(glog)
if (NOT glog_POPULATED)
    FetchContent_Populate(glog)
    set(WITH_GFLAGS OFF CACHE BOOL "" FORCE)
    add_subdirectory(${glog_SOURCE_DIR} ${glog_BINARY_DIR})
    target_link_libraries(3rdparty_stub INTERFACE glog::glog)
endif ()

# vulkan-headers
FetchContent_Declare(
    vulkan-headers
    URL https://github.com/KhronosGroup/Vulkan-Headers/archive/v1.2.169.zip
)
FetchContent_GetProperties(vulkan-headers)
if (NOT vulkan-headers_POPULATED)
    FetchContent_Populate(vulkan-headers)
    add_subdirectory(${vulkan-headers_SOURCE_DIR} ${vulkan-headers_BINARY_DIR})
    target_link_libraries(3rdparty_stub INTERFACE Vulkan::Headers)
    # 开启 _UNICODE 和 VK_USE_PLATFORM_WIN32_KHR 两个宏
    target_compile_definitions(3rdparty_stub INTERFACE VK_USE_PLATFORM_WIN32_KHR _UNICODE)
endif ()

# glfw
FetchContent_Declare(
    glfw
    URL https://github.com/glfw/glfw/archive/3.3.2.zip
)
FetchContent_GetProperties(glfw)
if (NOT glfw_POPULATED)
    FetchContent_Populate(glfw)
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
    target_link_libraries(3rdparty_stub INTERFACE glfw)
endif ()

# glslang
FetchContent_Declare(
    glslang
    URL https://github.com/KhronosGroup/glslang/archive/11.1.0.zip
)
FetchContent_GetProperties(glslang)
if (NOT glslang_POPULATED)
    FetchContent_Populate(glslang)
    set(BUILD_EXTERNAL OFF CACHE BOOL "" FORCE)
    set(ENABLE_HLSL OFF CACHE BOOL "" FORCE)
    add_subdirectory(${glslang_SOURCE_DIR} ${glslang_BINARY_DIR})
    target_link_libraries(3rdparty_stub INTERFACE glslang SPIRV glslang-default-resource-limits OSDependent)
endif ()

# Vulkan SDK
if ($ENV{VK_SDK_PATH})
    message("vulkan sdk path: " $ENV{VK_SDK_PATH})
    target_link_directories(3rdparty_stub INTERFACE $ENV{VK_SDK_PATH}/Lib)
    target_link_libraries(3rdparty_stub INTERFACE "vulkan-1")
else()
    target_compile_definitions(3rdparty_stub INTERFACE VK_NO_PROTOTYPES)
endif ()
