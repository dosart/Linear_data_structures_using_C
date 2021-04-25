cmake_minimum_required(VERSION 3.1)

project(vector)

include_directories(include)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -ggdb")

set(SOURCE_FILE src/vector.c)
set(HEADER_FILE include/vector.h)

add_library(vector STATIC ${SOURCE_FILE} ${HEADER_FILE})