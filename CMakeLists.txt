cmake_minimum_required(VERSION 3.6)
project(raw_sniffer)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(raw_sniffer ${SOURCE_FILES})