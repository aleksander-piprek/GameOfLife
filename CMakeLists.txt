cmake_minimum_required(VERSION 3.15)
project(GameOfLife)

find_package(SFML 2.5 COMPONENTS graphics audio system REQUIRED)

set(SOURCES "main.cpp"
            "src/game/game.cpp"
            "src/window/window.cpp")

add_executable(GameOfLife ${SOURCES} ${INCLUDES})

target_link_libraries(GameOfLife sfml-graphics sfml-audio sfml-system)