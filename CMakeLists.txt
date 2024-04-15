cmake_minimum_required(VERSION 3.27)
project(OfficialBugsCpp2)

set(CMAKE_CXX_STANDARD 17)

add_executable(OfficialBugsCpp2 main.cpp
        Board.cpp
        Board.h
        Bug.cpp
        Bug.h
        Crawler.cpp
        Crawler.h
        Hopper.cpp
        Hopper.h)
