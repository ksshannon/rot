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

#include "rot.h"

/* ROT13 definition.  Simple syntax change */
#define rot13(s) rot(s,13)

/*
** Apply arbitrary character shift to a string in place.
** rot("Test", 13)->
** Test -> Grfg
**
** return 0 on success, non-zero otherwise.
**/

int rot(char *s, int rot)
{
    char *p, c;
    p = s;
    if(!p)
    {
      return 1;
    }
    if(abs(rot) > 26)
    {
        rot = rot % 26;
    }
    if(rot < 0)
    {
        rot = 26 + rot;
    }
    while(*p != '\0')
    {
        if(!isalpha(*p))
        {
            p++;
            continue;
        }
        c = islower(*p) ? 'a' : 'A';
        *p = c + (*p - c + rot) % 26;
        p++;
    }
    return 0;
}

