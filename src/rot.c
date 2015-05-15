
#include "rot.h"

/*
** Apply arbitrary character shift to a string in place.
** rot("Test", 13)->
** Test -> Grfg
**/

int rot(char *s, int rot){
  char *p, c;
  p = s;
  if(!p) return 1;
  while(*p != '\0'){
    if(!isalpha(*p)){
      p++;
      continue;
    }
    c = islower(*p) ? 'a' : 'A';
    *p = c + (*p - c + rot) % 26, stdout;
    p++;
  }
  return 0;
}

int rot13(char *s){
  return rot(s, 13);
}
