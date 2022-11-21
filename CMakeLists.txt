cmake_minimum_required(VERSION 3.23)
project(clashG C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(vendors/librequests)

add_executable(clashG main.c)
target_link_libraries(clashG librequests)