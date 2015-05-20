
cmake_minimum_required(VERSION 2.6)
project(rot)

if(NOT MSVC)
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)
endif(NOT MSVC)

add_subdirectory(src)

add_subdirectory(ext)

include(CTest)
if(BUILD_TESTING)
  add_subdirectory(test)
endif(BUILD_TESTING)

