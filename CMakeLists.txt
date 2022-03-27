cmake_minimum_required(VERSION 3.1)
project(cppBrainFuck)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")


include_directories(.)


add_executable(BrainFuck interpreter.cpp state.cpp util.cpp)