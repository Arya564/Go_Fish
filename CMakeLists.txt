cmake_minimum_required(VERSION 3.17)
project(GoFish)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GoFish
        card.h
        go_fish.cpp
        deck.h
        player.h card.cpp deck.cpp player.cpp)
