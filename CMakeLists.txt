cmake_minimum_required(VERSION 3.21)
project(TheSnowCosimo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TheSnowCosimo
    main.cpp
    backend/components/map/chunk/Chunk.cpp
    backend/components/map/Level.cpp


        )
