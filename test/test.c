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

void usage(){
  printf("rottest file\n");
  printf("\n");
  printf("where the file contains two strings, input and expected result\n");
  exit(1);
}

#ifndef ROT_TEST_MAX_BUF
#define ROT_TEST_MAX_BUF 512
#endif

int main(int argc,
         char* argv[])
{
  int rc;
  FILE *fin;
  char *input, *expected, *szrot;
  int nrot;

  if(argc < 2) usage();

  input = malloc(ROT_TEST_MAX_BUF);
  if(!input) return 1;
  expected = malloc(ROT_TEST_MAX_BUF);
  if(!expected) return 1;
  szrot = malloc(ROT_TEST_MAX_BUF);
  if(!input || !expected || !szrot){
    free(input);
    free(expected);
    free(szrot);
    return 1;
  }
  fin = fopen(argv[1], "r");
  if(!fin) return 1;
  input = fgets(input, ROT_TEST_MAX_BUF, fin);
  if(!input){
    fclose(fin);
    return 1;
  }
  if(input[strlen(input)-1] == '\n')
    input[strlen(input)-1] = '\0';
  expected = fgets(expected, ROT_TEST_MAX_BUF, fin);
  if(!expected){
    fclose(fin);
    return 1;
  }
  if(expected[strlen(expected)-1] == '\n')
    expected[strlen(expected)-1] = '\0';
  szrot = fgets(szrot, ROT_TEST_MAX_BUF, fin);
  if(!szrot){
    fclose(fin);
    return 1;
  }
  nrot = atoi(szrot);
  rc = rot(input, nrot);
  if(rc == 0){
    rc = strcmp(input, expected);
  }
  free(input);
  free(expected);
  free(szrot);
  fclose(fin);
  return rc;
}

