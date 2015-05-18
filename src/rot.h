
#ifndef ROT_H_
#define ROT_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define strequal(a,b) strcmp(a,b)==0
#define strnequal(a,b,n) strncmp(a,b,n)==0

int rot(char* s, int rot);
int rot13(char* s);

#endif /* ROT_H_ */

