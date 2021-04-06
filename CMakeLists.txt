cmake_minimum_required(VERSION 3.16)
project(CSVReader)

set(CMAKE_CXX_STANDARD 14)

include_directories(CSVReader)

add_executable(CSVReader
        read_csv.cpp
        read_csv.h sample_usage.cpp)
