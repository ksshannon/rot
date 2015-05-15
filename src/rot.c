
#include "rot.h"

/*
** Apply 13 character to a string in place.
**
** Test -> Grfg
**/

int rot13(char *s){
  char *p, c;
  p = s;
  if(!p) return 1;
  while(*p != '\0'){
    if(!isalpha(*p)){
      p++;
      continue;
    }
    c = islower(*p) ? 'a' : 'A';
    *p = c + (*p - c + 13) % 26, stdout;
    p++;
  }
  return 0;
}

