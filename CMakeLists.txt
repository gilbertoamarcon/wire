cmake_minimum_required(VERSION 3.7)

project(wire)

find_package(SDL2 REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB_RECURSE LIBS src/*/*.cpp)

add_library(libs ${LIBS})

add_executable(main src/main.cpp)
add_executable(tests tests/test.cpp)


target_link_libraries(main libs)
target_link_libraries(main ${SDL2_LIBRARIES})
target_link_libraries(main yaml-cpp)
target_link_libraries(tests libs)

enable_testing()
add_test(NAME tests COMMAND tests)

