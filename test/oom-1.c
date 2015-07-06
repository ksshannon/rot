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

#if defined(__GNUC__)

#include <malloc.h>
#include "rot.h"

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#pragma GCC push

static void rot_init_hook(void);
static void * oomalloc(size_t n, const void *f);

void (*__MALLOC_HOOK_VOLATILE __malloc_initialize_hook)(void) = rot_init_hook;

static void rot_init_hook(void)
{
    __malloc_hook = oomalloc;
}

static void * oomalloc(size_t n, const void *f)
{
    (void)n;
    (void*)f;
    return 0;
}

int main()
{
    return rot(0, 1);
}
#else
int main()
{
    return 1;
}
#endif

