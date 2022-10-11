cmake_minimum_required(VERSION 3.24)
project(Project)

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/out")

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Library)
add_subdirectory(UnitTests)