cmake_minimum_required(VERSION 3.28)
project(AdvancedBitmapOutput LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(SRC
    src/encoder.cpp
    src/main.cpp
    src/patternGenerator.cpp
)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PRIVATE "include/")
