##
## This is free and unencumbered software released into the public domain.
##
## Anyone is free to copy, modify, publish, use, compile, sell, or
## distribute this software, either in source code form or as a compiled
## binary, for any purpose, commercial or non-commercial, and by any
## means.
##
## In jurisdictions that recognize copyright laws, the author or authors
## of this software dedicate any and all copyright interest in the
## software to the public domain. We make this dedication for the benefit
## of the public at large and to the detriment of our heirs and
## successors. We intend this dedication to be an overt act of
## relinquishment in perpetuity of all present and future rights to this
## software under copyright law.
##
## THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
## EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
## MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
## IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
## OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
## ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
## OTHER DEALINGS IN THE SOFTWARE.
##
## For more information, please refer to <http://unlicense.org/>
##

cmake_minimum_required(VERSION 2.6)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(rottest test.c)
target_link_libraries(rottest rot)

set(tests "shift13-1 | kyle | 13 | xlyr"
          "shift13-2 | abc  | 13 | nop"
          "shift1-1  | abc  | 1  | bcd"
          "shift1-2  | xyz  | 1  | abc")

foreach(test ${tests})
  string(REPLACE "|" ";" args ${test})
  list(GET args 0 testname)
  list(GET args 1 input)
  list(GET args 2 shift)
  list(GET args 3 exp)
  #message(${testname} "${CMAKE_BINARY_DIR}/src/rot --shift ${shift} '${input}'")
  add_test(${testname} ${CMAKE_BINARY_DIR}/src/rot "--shift ${shift} '${input}'")
  set_tests_properties(${testname} PROPERTIES PASS_REGULAR_EXPRESSION "${exp}")
endforeach(test ${tests})

if(BUILD_LUA_BINDINGS)
  add_subdirectory(lua)
endif(BUILD_LUA_BINDINGS)

