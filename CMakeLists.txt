cmake_minimum_required(VERSION 3.29)
project(eyeject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(eyeject 
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

target_include_directories(eyeject PRIVATE include)
target_link_directories(eyeject PRIVATE lib)

if(WIN32)
    target_link_libraries(eyeject PRIVATE SDL3)
else()
    target_link_libraries(eyeject PRIVATE SDL3 ncurses)
endif()
