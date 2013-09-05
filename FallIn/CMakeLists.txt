cmake_minimum_required (VERSION 2.8)
project (FallIn CXX)

add_subdirectory(ugdk)
include_directories(${UGDK_EXTERNAL_INCLUDE_DIRS})

add_definitions(-std=c++11)

add_executable (FallIn src/FallIn.cpp src/AMB/DrawableImage.cpp)
target_link_libraries(FallIn libugdk)
