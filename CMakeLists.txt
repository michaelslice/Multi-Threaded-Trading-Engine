cmake_minimum_required(VERSION 3.10)
project(TradingEngine)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Globbing to collect source files
file(GLOB_RECURSE SOURCES 
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${PROJECT_SOURCE_DIR}/CurrentTime/*.cpp"
    "${PROJECT_SOURCE_DIR}/Orderbook/*.cpp"
    "${PROJECT_SOURCE_DIR}/Order/*.cpp"
    "${PROJECT_SOURCE_DIR}/OrderId/*.cpp"
    "${PROJECT_SOURCE_DIR}/OrderStatus/*.cpp"
    "${PROJECT_SOURCE_DIR}/OrderType/*.cpp"
    "${PROJECT_SOURCE_DIR}/Side/*.cpp"
    "${PROJECT_SOURCE_DIR}/Test/*.cpp"
)

# Ignore CMake-generated files
list(FILTER SOURCES EXCLUDE REGEX ".*CMakeCXXCompilerId.cpp$")

# Add executable target, using all files listed in SOURCES
add_executable(TRADING ${SOURCES})

file(COPY "${PROJECT_SOURCE_DIR}/Test/TestFiles/orders.txt" DESTINATION "${CMAKE_BINARY_DIR}")