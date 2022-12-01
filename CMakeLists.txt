cmake_minimum_required(VERSION 3.21)
project(TheSnowCosimo)

set(CMAKE_CXX_STANDARD 14)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(TheSnowCosimo
    main.cpp
    backend/components/map/chunk/Chunk.cpp
    backend/components/map/Level.cpp
    frontend/mapgui/MapGUI.cpp
    frontend/Gui.cpp
    backend/Game.cpp
)
