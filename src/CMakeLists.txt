
cmake_minimum_required(VERSION 2.6)

add_library(rot SHARED rot.c)
add_library(rot-static STATIC rot.c)
set_target_properties(rot-static PROPERTIES OUTPUT_NAME rot)
add_executable(rot-bin main.c)
set_target_properties(rot-bin PROPERTIES OUTPUT_NAME rot)
target_link_libraries(rot-bin rot)

