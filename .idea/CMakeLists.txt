cmake_minimum_required(VERSION 3.10)
project(RayTracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(RayTracer
        main.cpp
        ../main.cpp
        ../main.cpp
        ../material.h
)

target_include_directories(RayTracer PRIVATE ${CMAKE_SOURCE_DIR})