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

file(GLOB test_cases "${PROJECT_SOURCE_DIR}/test/*.test")

foreach(case ${test_cases})
  get_filename_component(base ${case} NAME_WE)
  add_test(lua_${base} lua5.1 ${PROJECT_SOURCE_DIR}/test/lua/test.lua ${case})
  set_tests_properties(lua_${base} PROPERTIES ENVIRONMENT
                       "LUA_CPATH=${CMAKE_BINARY_DIR}/ext/lua/librotate.so")
endforeach(case ${test_cases})

file(GLOB test_cases "${PROJECT_SOURCE_DIR}/test/lua/luatest*.lua")

foreach(case ${test_cases})
  get_filename_component(base ${case} NAME_WE)
  add_test(${base} lua5.1 ${case})
  set_tests_properties(${base} PROPERTIES ENVIRONMENT
                       "LUA_CPATH=${CMAKE_BINARY_DIR}/ext/lua/librotate.so")
endforeach(case ${test_cases})

