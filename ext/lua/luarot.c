/*
** This is free and unencumbered software released into the public domain.
**
** Anyone is free to copy, modify, publish, use, compile, sell, or
** distribute this software, either in source code form or as a compiled
** binary, for any purpose, commercial or non-commercial, and by any
** means.
**
** In jurisdictions that recognize copyright laws, the author or authors
** of this software dedicate any and all copyright interest in the
** software to the public domain. We make this dedication for the benefit
** of the public at large and to the detriment of our heirs and
** successors. We intend this dedication to be an overt act of
** relinquishment in perpetuity of all present and future rights to this
** software under copyright law.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
** OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
** OTHER DEALINGS IN THE SOFTWARE.
**
** For more information, please refer to <http://unlicense.org/>
*/

#define LUA_LIB

#include "rot.h"
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static int l_rot(lua_State *L){
  char *p;
  int rc, r, n;
  size_t l;
  const char *s;
  n = lua_gettop(L);
  if(!luaL_checkstring(L, 1)){
    lua_pushstring(L, "Invalid argument");
    lua_error(L);
  }
  s = lua_tostring(L, 1);
  r = 13;
  if(n > 1){
    if(!lua_isnumber(L,2)){
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

int luaopen_librotate(lua_State *L){
  lua_register(L, "rotate", l_rot);
  return 0;
}

static const luaL_reg rotlib[] = {
    {"rotate", l_rot},
    {NULL, NULL}
};

