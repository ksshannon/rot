
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test.lua
  ${CMAKE_CURRENT_BINARY_DIR} COPY_ONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CTestCustom.cmake
               ${CMAKE_BINARY_DIR}CTestCustom.cmake COPY_ONLY)

file(GLOB test_cases "${PROJECT_SOURCE_DIR}/test/*.test")

foreach(case ${test_cases})
  get_filename_component(base ${case} NAME_WE)
  add_test(lua_${base} lua5.1 ${PROJECT_SOURCE_DIR}/test/lua/test.lua ${case})
  set_tests_properties(lua_${base} PROPERTIES ENVIRONMENT
                       "LUA_CPATH=${CMAKE_BINARY_DIR}/ext/lua/librotate.so")
  #ignore in memcheck
  set(CTEST_CUSTOM_MEMCHECK_IGNORE ${CTEST_CUSTOM_MEMCHECK_IGNORE} lua_${base})
endforeach(case ${test_cases})

