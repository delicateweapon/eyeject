cmake_minimum_required(VERSION 3.29)
project(spark)

add_executable(spark main.cpp App.cpp Input.cpp)

target_include_directories(spark PRIVATE include)

target_link_directories(spark PRIVATE lib)
target_link_libraries(spark PRIVATE SDL3)
