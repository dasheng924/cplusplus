cmake_minimum_required(VERSION 3.5)

project(thread_mutex LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(thread_mutex main.cpp)
