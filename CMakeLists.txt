cmake_minimum_required(VERSION 3.12)

project(wfind)
set(CMAKE_CXX_STANDARD 17)

add_library(wfind_lib STATIC lib/wfind.cpp)

add_executable(wfind main.cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.0)
        target_link_libraries(wfind wfind_lib stdc++fs)
    else(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.0)
        target_link_libraries(wfind wfind_lib)
    endif(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.0)
else(CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    target_link_libraries(wfind wfind_lib)
endif(CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
