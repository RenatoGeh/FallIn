cmake_minimum_required (VERSION 2.8)
project (FallIn CXX)

add_subdirectory(ugdk)
include_directories(${UGDK_EXTERNAL_INCLUDE_DIRS})

add_definitions(-std=c++11)

add_executable (FallIn
	src/FallIn.cpp
	src/AMB/DrawableImage.cpp
	src/AMB/Tile.cpp
	src/AMB/TileMap.cpp
	src/AMB/Area.cpp
	src/AMB/Vector2D.cpp
        src/AMB/Camera.cpp
        src/AMB/Actor.cpp
        src/AMB/Player.cpp
)
target_link_libraries(FallIn libugdk)
