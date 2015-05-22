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
 
# Autotest
#          Test name   | input | shift | output
set(tests "shift01-1   | abc   | 01    | bcd"
          "shift01-2   | xyz   | 01    | yza"
          "shift02-1   | abc   | 02    | cde"
          "shift03-1   | abc   | 03    | def"
          "shift04-1   | abc   | 04    | efg"
          "shift05-1   | abc   | 05    | fgh"
          "shift06-1   | abc   | 06    | ghi"
          "shift07-1   | abc   | 07    | hij"
          "shift08-1   | abc   | 08    | ijk"
          "shift09-1   | abc   | 09    | jkl"
          "shift10-1   | abc   | 10    | klm"
          "shift11-1   | abc   | 11    | lmn"
          "shift12-1   | abc   | 12    | mno"
          "shift13-1   | abc   | 13    | nop"
          "shift14-1   | abc   | 14    | opq"
          "shift15-1   | abc   | 15    | pqr"
          "shift16-1   | abc   | 16    | qrs"
          "shift17-1   | abc   | 17    | rst"
          "shift18-1   | abc   | 18    | stu"
          "shift19-1   | abc   | 19    | tuv"
          "shift20-1   | abc   | 20    | uvw"
          "shift21-1   | abc   | 21    | vwx"
          "shift22-1   | abc   | 22    | wxy"
          "shift23-1   | abc   | 23    | xyz"
          "shift24-1   | abc   | 24    | yza"
          "shift25-1   | abc   | 25    | zab"
          "shift26-1   | abc   | 26    | abc"
          "shift27-1   | abc   | 27    | bcd"
          "shift255-1  | abc   | 255   | vwx"
          "shift-01-1  | abc   | -1    | zab"
          "shift-09-1  | abc   | -9    | rst"
          "shift-10-1  | abc   | -10   | qrs"
          "shift-11-1  | abc   | -11   | pqr"
          "shift-12-1  | abc   | -12   | opq"
          "shift-13-1  | abc   | -13   | nop"
          "shift-14-1  | abc   | -14   | mno"
          "shift-15-1  | abc   | -15   | lmn"
          "shift-16-1  | abc   | -16   | klm"
          "shift-17-1  | abc   | -17   | jkl"
          "shift-18-1  | abc   | -18   | ijk"
          "shift-19-1  | abc   | -19   | hij"
          "shift-20-1  | abc   | -20   | ghi"
          "shift-21-1  | abc   | -21   | fgh"
          "shift-22-1  | abc   | -22   | efg"
          "shift-23-1  | abc   | -23   | def"
          "shift-24-1  | abc   | -24   | cde"
          "shift-25-1  | abc   | -25   | bcd"
          "shift-26-1  | abc   | -26   | abc"
          "shift-27-1  | abc   | -27   | zab"
          "cap-1       | ABC   | 01    | BCD"
          "num-1       | 123   | 01    | 123"
          "lspace-1    | ' abc'| 01    | ' bcd'"
          "word2-1     | 'a b' | 01    | 'b c'")

set(rotbin ${CMAKE_BINARY_DIR}/src/rot)

message(STATUS "Generating tests...")
foreach(test ${tests})
  string(REGEX REPLACE "\\|" ";" args ${test})
  list(GET args 0 testname)
  list(GET args 1 input)
  string(STRIP ${input} input)
  list(GET args 2 shift)
  string(STRIP ${shift} shift)
  list(GET args 3 exp)
  string(STRIP ${exp} exp)
  #message(${testname} ${rotbin} --shift ${shift} \"${input}\")
  add_test(${testname} ${rotbin} --shift ${shift} \"${input}\")
  set_tests_properties(${testname} PROPERTIES PASS_REGULAR_EXPRESSION \"${exp}\")
endforeach(test ${tests})

# Special tests

add_test(noshift-1 ${rotbin} abc)
set_tests_properties(noshift-1 PROPERTIES PASS_REGULAR_EXPRESSION "nop")

# Tests that should fail
add_test(noargs ${rotbin})
add_test(invalidarg ${rotbin} abc --noargs)
add_test(shift-no-input-1 ${rotbin} --shift)
add_test(shift-no-input-2 ${rotbin} --shift 0)

set(failures ${failures} noargs shift-no-input-1 shift-no-input-2 invalidarg)

foreach(failure ${failures})
  message(STATUS "Adding ${failure} to expected failure list.")
  set_tests_properties(${failure} PROPERTIES WILL_FAIL TRUE)
endforeach(failure ${failures})

# C based tests
file(GLOB ctests ${PROJECT_SOURCE_DIR}/test/*.c)
foreach(test ${ctests})
  get_filename_component(base ${test} NAME_WE)
  add_executable(${base} ${test})
  target_link_libraries(${base} rot)
  add_test(${base} ${base})
endforeach(test ${ctests})

set(failures ${failures} null-1)

foreach(failure ${failures})
  message(STATUS "Adding ${failure} to expected failure list.")
  set_tests_properties(${failure} PROPERTIES WILL_FAIL TRUE)
endforeach(failure ${failures})


if(BUILD_LUA_BINDINGS)
  add_subdirectory(lua)
endif(BUILD_LUA_BINDINGS)

if(BUILD_COVERAGE)
  add_custom_target(coverage lcov --directory ${CMAKE_BINARY_DIR}
                                  --zerocounters
                    COMMAND make test
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test
                    COMMAND lcov --directory ${CMAKE_BINARY_DIR}/src
                                 --directory ${CMAKE_BINARY_DIR}/ext
                                 --capture
                                 --output-file rotcov.info
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test
                    COMMAND  genhtml rotcov.info
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test
                    COMMAND  firefox index.html
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test)
endif(BUILD_COVERAGE)

