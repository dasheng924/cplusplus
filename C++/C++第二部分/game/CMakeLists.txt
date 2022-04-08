cmake_minimum_required(VERSION 3.17)
project(game)

set(CMAKE_CXX_STANDARD 11)

add_executable(game main.cpp weapon.h knife.cpp knife.h DragonSword.cpp DragonSword.h Hero.cpp Hero.h Monster.cpp Monster.h)