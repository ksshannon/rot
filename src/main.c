
#include "rot.h"

void Usage(){
  printf("rot input\n");
  printf("\n");
  exit(1);
}

int main(int argc,
         char* argv[]){
  char *p;

  if(argc < 2) Usage();

  p = argv[1];
  while(*p != '\0'){
    putc('a' + (tolower((*p++)) - 'a' + 13) % 26, stdout);
  }
  printf("\n");
  return 0;
}

