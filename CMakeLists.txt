cmake_minimum_required(VERSION 3.21)
project(TheSnowCosimo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})


add_executable(TheSnowCosimo
main.cpp
backend/components/map/chunk/Chunk.cpp
backend/components/map/Level.cpp
backend/components/entity/Entity.cpp
backend/components/entity/player/Player.cpp
frontend/Gui.cpp
frontend/mapgui/MapGUI.cpp
)
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

set(CMAKE_BUILD_TYPE Debug)