cmake_minimum_required(VERSION 3.10)
project(mazegame)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

set(SOURCES src/main.cpp src/player.cpp src/game.cpp)
add_executable(mazegame WIN32 ${SOURCES})

if(TARGET SDL2::SDL2main)
    target_link_libraries(mazegame PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(mazegame PRIVATE SDL2::SDL2)
