cmake_minimum_required(VERSION 3.29)
project(eyeject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SOURCE_FILES
    src/main.cpp
    src/App.cpp
    src/Input.cpp
    src/Color.cpp
    src/Draw.cpp
    src/Point2D.cpp
    src/Camera.cpp
    src/Garden.cpp
    src/Console.cpp
)

set(HEADER_FILES
    src/App.hpp
    src/Color.hpp
    src/Point2D.hpp
    src/Camera.hpp
    src/Garden.hpp
    src/Console.hpp
    src/constants.hpp
)

add_executable(eyeject ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(eyeject PRIVATE include)
target_link_directories(eyeject PRIVATE lib)

if(WIN32)
    target_link_libraries(eyeject PRIVATE SDL3)
else()
    target_link_libraries(eyeject PRIVATE SDL3 ncurses)
endif()

