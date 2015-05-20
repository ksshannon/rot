
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
ROT_DLL int rot13(char* s);

ROT_C_END

#endif /* ROT_H_ */

