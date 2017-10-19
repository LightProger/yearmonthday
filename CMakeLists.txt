cmake_minimum_required(VERSION 3.8)
project(yearmonthday)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES ymd.c)
add_executable(yearmonthday ${SOURCE_FILES})