cmake_minimum_required(VERSION 3.10)
project(TradingEngine)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# This will make the executable file appear in the source directory
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")

# Globbing to collect source files
file(GLOB_RECURSE SOURCES 
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${PROJECT_SOURCE_DIR}/CurrentTime/*.cpp"
)

# Ignore CMake-generated files
list(FILTER SOURCES EXCLUDE REGEX ".*CMakeCXXCompilerId.cpp$")

# Add executable target, using all files listed in SOURCES
add_executable(TRADING ${SOURCES})