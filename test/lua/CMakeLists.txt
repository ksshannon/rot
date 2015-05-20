
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test.lua
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
set(CTEST_ENVIRONMENT "LUA_CPATH=${CMAKE_BINARY_DIR}/ext/lua/librotate.so")

file(GLOB test_cases "${PROJECT_SOURCE_DIR}/test/*.test")

foreach(case ${test_cases})
  get_filename_component(base ${case} NAME_WE)
  add_test(lua_${base} lua5.1 ${PROJECT_SOURCE_DIR}/test/lua/test.lua ${case})
endforeach(case ${test_cases})

