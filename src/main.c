
#include "rot.h"

void Usage(){
  printf("rot input\n");
  printf("\n");
  exit(1);
}

int main(int argc,
         char* argv[]){
  char *p;
  char  offset;
  int rc;

  if(argc < 2) Usage();

  p = strdup(argv[1]);
  rc = rot13(p);
  if(rc == 0) printf("%s\n", p);
  free(p);
  return rc;
}

