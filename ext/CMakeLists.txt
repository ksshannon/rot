
option(BUILD_LUA_BINDING "Build bindings for lua" OFF)

if(BUILD_LUA_BINDING)
  add_subdirectory(lua)
endif(BUILD_LUA_BINDING)

