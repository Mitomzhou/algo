cmake_minimum_required(VERSION 3.17)
project(algo)

set(CMAKE_CXX_STANDARD 11)


add_subdirectory(math)


add_executable(algo main.cpp)
#target_link_libraries(algo math)