
option(BUILD_LUA_BINDINGS "Build bindings for lua" OFF)

if(BUILD_LUA_BINDINGS)
  add_subdirectory(lua)
endif(BUILD_LUA_BINDINGS)

