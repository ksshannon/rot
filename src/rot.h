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

#ifndef ROT_H_
#define ROT_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32)
#if defined(rot_EXPORTS)
  #define ROT_DLL     __declspec(dllexport)
#else
  #define ROT_DLL     __declspec(dllimport)
#endif /* rot_EXPORTS */
#else
  #define ROT_DLL
#endif /* _WIN32 */

#ifdef __cplusplus
  #define ROT_C_START extern "C" {
  #define ROT_C_END   }
#else
  #define ROT_C_START
  #define ROT_C_END
#endif

#define strequal(a,b) strcmp(a,b)==0
#define strnequal(a,b,n) strncmp(a,b,n)==0

ROT_C_START

ROT_DLL int rot(char* s, int rot);

ROT_C_END

#endif /* ROT_H_ */

