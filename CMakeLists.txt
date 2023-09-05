cmake_minimum_required(VERSION 3.26)
project(system_monitoring)

set(CMAKE_CXX_STANDARD 20)

add_executable(system_monitoring main.cpp
        system-data/cpu-usage.cpp
        system-data/cpu-usage.h)
