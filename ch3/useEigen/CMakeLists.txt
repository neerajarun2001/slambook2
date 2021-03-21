cmake_minimum_required(VERSION 3.0)
project(useEigen)

set(CMAKE_BUILD_TYPE "Release")
# add header file
include_directories("/usr/local/include/eigen3/")
add_executable(eigenMatrix eigenMatrix.cpp)
