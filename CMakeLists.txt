cmake_minimum_required(VERSION 3.12)

project(wfind)

add_library(wfind_lib STATIC lib/wfind.cpp)

add_executable(wfind main.cpp)

target_link_libraries(wfind wfind_lib stdc++fs)
