cmake_minimum_required(VERSION 3.29)
project(eyeject)

add_executable(eyeject main.cpp App.cpp Input.cpp)

target_include_directories(eyeject PRIVATE include)

target_link_directories(eyeject PRIVATE lib)
target_link_libraries(eyeject PRIVATE SDL3)
