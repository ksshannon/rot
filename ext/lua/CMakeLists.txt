
include(FindLua51)
find_package(Lua51)

include_directories(${PROJECT_SOURCE_DIR}/src
                    ${LUA_INCLUDE_DIR})

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -fPIC)

add_library(rotate SHARED luarot.c)
#set_target_properties(rotate PROPERTIES OUTPUT_NAME rotate)
target_link_libraries(rotate rot ${LUA_LIBRARIES})
