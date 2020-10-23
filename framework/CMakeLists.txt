file(GLOB_RECURSE SOURCE_LIST *.h *.cpp)
add_library(framework ${SOURCE_LIST})
target_link_libraries(framework 3rdparty_stub)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    target_compile_definitions(framework PRIVATE -DVK_USE_PLATFORM_WIN32_KHR)
endif ()

# interface
target_include_directories(framework INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})