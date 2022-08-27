cmake_minimum_required(VERSION 3.18.0)

project(game VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set(HEADERS 
    allMove.h
    Board.h
    Cell.h
    Game.h
    IO.h
    )

set(SOURCES
    allMove.cpp
    Board.cpp
    Cell.cpp
    Game.cpp
    IO.cpp
    )

add_executable(${PROJECT_NAME} main.cpp ${HEADERS} ${SOURCES})

set_target_properties(game PROPERTIES
                    CXX_STANDARD 11
                    CXX_STANDARD_REQUIRED ON                   
)