cmake_minimum_required(VERSION 3.10.0)

project(reset_zero_positon)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

set(CMAKE_BUILD_TYPE "Debug")

link_directories(PRIVATE ${CMAKE_SOURCE_DIR}/lib)
add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/reset_position.cpp)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/libeu_harmonic.so)