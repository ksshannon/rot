
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

