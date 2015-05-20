
#define LUA_LIB

#include "rot.h"
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static int l_rot(lua_State *L){
  char *p;
  int rc, r, n;
  const char *s;
  n = lua_gettop(L);
  if(!lua_checkstring(L, 1, &s)){
    lua_pushstring(L, "Invalid argument");
    lua_error(L);
  }
  s = lua_tostring(L, 1);
  r = 13;
  if(n > 1){
    if(!luaL_isnumber(L,2)){
      lua_pushstring(L, "Invalid argument");
      lua_error(L);
    }
    r = lua_tonumber(L, 2);
  }
  p = strdup(s);
  rc = rot(p, (int)r);
  if(rc){
    lua_pushstring(L, "Failed to rotate.");
    lua_error(L);
  }
  lua_pushstring(L, p);
  free(p);
  return 1;
}

static const luaL_reg rotlib[] = {
    {"rotate", l_rot},
    {NULL, NULL}
};

