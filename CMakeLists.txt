cmake_minimum_required(VERSION 3.10)
project(NanoDB)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    test_runner.cpp
    src/logger/Logger.cpp
    src/pager/BufferPool.cpp
    src/parser/Parser.cpp
    src/storage/DiskManager.cpp
    src/storage/Loader.cpp
    src/storage/Table.cpp
    src/optimizer/JoinOptimizer.cpp
)

add_executable(NanoDB ${SOURCES})
