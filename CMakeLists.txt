cmake_minimum_required(VERSION 3.27)
project(djks)

set(CMAKE_CXX_STANDARD 17)

# Main executable
add_executable(djks src/Main.cpp
        src/Graph/Graph.cpp
        src/Solver/Dijkstra.cpp
)

target_include_directories(djks PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)

# Tests
add_executable(djks_tests
        src/Graph/Graph.cpp
        src/Solver/Dijkstra.cpp
        tests/GraphTests.cpp
        tests/DijkstraTests.cpp
)

target_include_directories(djks_tests PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)