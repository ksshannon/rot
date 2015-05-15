
cmake_minimum_required(VERSION 2.6)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(rottest test.c ${PROJECT_SOURCE_DIR}/src/rot.c)

file(GLOB test_cases "*.test")

foreach(case ${test_cases})
  get_filename_component(base ${case} NAME_WE)
  add_test(${base} rottest ${case})
endforeach(case ${test_cases})

