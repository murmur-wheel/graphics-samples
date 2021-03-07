cmake_minimum_required(VERSION 3.19)
project(graphics-samples)

set(CMAKE_CXX_STANDARD 17)

include(3rdparty_stub.cmake)
add_subdirectory(framework)
add_subdirectory(samples)
