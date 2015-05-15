
cmake_minimum_required(VERSION 2.6)
project(rot)

add_subdirectory(src)
include(CTest)
if(BUILD_TESTING)
  add_subdirectory(test)
endif(BUILD_TESTING)

