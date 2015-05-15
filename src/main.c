
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

  if(argc < 2) Usage();

  p = argv[1];
  while(*p != '\0'){
    offset = islower(*p) ? 'a' : 'A';
    putc(offset + ((*p++) - offset + 13) % 26, stdout);
  }
  printf("\n");
  return 0;
}

