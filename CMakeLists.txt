cmake_minimum_required(VERSION 3.21)
project(TheSnowCosimo)

set(CMAKE_CXX_STANDARD 14)

<<<<<<< HEAD
include_directories(.)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})


add_executable(TheSnowCosimo
main.cpp
backend/components/map/chunk/Chunk.cpp
backend/components/map/Level.cpp
backend/components/entity/Entity.cpp
)
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
=======
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(TheSnowCosimo
    main.cpp
    backend/components/map/chunk/Chunk.cpp
    backend/components/map/Level.cpp
    frontend/mapgui/MapGUI.cpp
    frontend/Gui.cpp
)
>>>>>>> ecfd7fd698f9902515e9f3440c44dcc55de10b2e
