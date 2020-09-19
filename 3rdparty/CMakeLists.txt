include(FetchContent)
add_library(3rdparty_stub INTERFACE)

FetchContent_Declare(
        vulkan-header
        URL https://github.com/KhronosGroup/Vulkan-Headers/archive/v1.2.153.zip
)
FetchContent_GetProperties(vulkan-header)
if (NOT vulkan-header_POPULATED)
    FetchContent_Populate(vulkan-header)
    add_subdirectory(${vulkan-header_SOURCE_DIR} ${vulkan-header_BINARY_DIR})
    target_link_libraries(3rdparty_stub INTERFACE Vulkan::Headers)
endif ()