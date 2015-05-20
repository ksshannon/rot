
#include "rot.h"

void usage(){
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

  if(argc < 2) usage();

  i = 1;
  while(i < argc){
    if(strequal(argv[i], "--shift")){
      if(i < argc - 2)
        shift = atoi(argv[++i]);
      else
        usage();
    }
    else if(p == NULL)
      p = argv[i];
    else
      usage();
    i++;
  }
  if(!p) usage();

  p = strdup(p);
  rc = rot(p, shift);
  if(rc == 0) printf("%s\n", p);
  free(p);
  return rc;
}

