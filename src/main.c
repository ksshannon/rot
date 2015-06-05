
#include "rot.h"

void usage(){
  printf("rot [--shift n] input\n");
  printf("\n");
  exit(1);
}

int main(int argc,
         char* argv[]){
  unsigned char *p = NULL;
  unsigned char *s = NULL;
  unsigned char  offset;
  uint32 shift = 13;
  uint32 i;
  uint32 rc;

  if(argc < 2){
    usage();
  }

  i = 1;
  while(i < argc){
    if(strequal(argv[i], "--shift")){
      if(i < argc - 2){
        shift = atoi(argv[++i]);
      }
      else{
        usage();
      }
    }
    else if(s == NULL){
      s = argv[i];
    }
    else{
      usage();
    }
    i++;
  }
  p = malloc(strlen(s) + 1);
  if(!p){
    return 1;
  }
  strcpy(p, s);
  rc = rot(p, shift);
  if(rc == 0){
    printf("%s\n", p);
  }
  free(p);
  return rc;
}

