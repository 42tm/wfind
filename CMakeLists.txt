cmake_minimum_required(VERSION 3.12)
project(wfind VERSION 1.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-std=c++17 -O3 -Wall -Wextra -Wpedantic")

set(SOURCE_FILES
    main.cpp
)

add_library(wfind_lib STATIC lib/wfind.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} wfind_lib stdc++fs)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)