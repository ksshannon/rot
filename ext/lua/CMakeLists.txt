
include(FindLua51)
find_package(Lua51 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src
                    ${LUA_INCLUDE_DIR})

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -fPIC)

add_library(rotate SHARED luarot.c)
target_link_libraries(rotate rot ${LUA_LIBRARIES})

