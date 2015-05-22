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

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test.lua
               ${CMAKE_CURRENT_BINARY_DIR})


set(rotlua ${PROJECT_SOURCE_DIR}/test/lua/test.lua)
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
  set(luatest lua-${testname})
  add_test(${luatest} lua5.1 ${rotlua} --shift ${shift} \"${input}\")
  set_tests_properties(${luatest} PROPERTIES PASS_REGULAR_EXPRESSION \"${exp}\")
  set_tests_properties(${luatest} PROPERTIES ENVIRONMENT
                       "LUA_CPATH=${CMAKE_BINARY_DIR}/ext/lua/?.so")
endforeach(test ${tests})

