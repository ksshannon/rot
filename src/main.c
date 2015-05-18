
#include "rot.h"

void Usage(){
  printf("rot [--shift n] input\n");
  printf("\n");
  exit(1);
}

int main(int argc,
         char* argv[]){
  char *p = NULL;
  char  offset;
  int   shift = 13;
  int   i, rc;

  if(argc < 2) Usage();

  i = 1;
  while(i < argc){
    if(strcmp(argv[i], "--shift") == 0)
      shift = atoi(argv[++i]);
    else if(p == NULL)
      p = argv[i];
    i++;
  }
  if(!p) Usage();

  p = strdup(p);
  rc = rot(p, shift);
  if(rc == 0) printf("%s\n", p);
  free(p);
  return rc;
}

