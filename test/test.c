
#include "rot.h"

void usage(){
  printf("rottest file\n");
  printf("\n");
  printf("where the file contains two strings, input and expected result\n");
  exit(1);
}

int main(int argc,
         char* argv[])
{
  int rc;
  FILE *fin;
  char input[512], expected[512];

  if(argc < 2) usage();

  fin = fopen(argv[1], "r");
  if(!fin) return 1;
  rc = fscanf(fin, "%s %s", &input, &expected);
  if(rc != 2) return 1;
  rc = rot13(input);
  if(rc) return 1;
  rc = strcmp(input, expected);
  return rc;
}
