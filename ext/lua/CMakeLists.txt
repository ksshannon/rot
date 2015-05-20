
include(FindLua51)
find_package(Lua51)

include_directories(${PROJECT_SOURCE_DIR}/src
                    ${LUA_INCLUDE_DIR})

add_library(luarot SHARED lua-rot.c)
target_link_libraries(luarot rot ${LUA_LIBRARIES})
