
#include "rot.h"

void usage(){
  printf("rottest file\n");
  printf("\n");
  printf("where the file contains two strings, input and expected result\n");
  exit(1);
}

#ifndef ROT_TEST_MAX_BUF
#define ROT_TEST_MAX_BUF 512
#endif

int main(int argc,
         char* argv[])
{
  int rc;
  FILE *fin;
  char *input, *expected, *szrot;
  int nrot;

  if(argc < 2) usage();

  input = malloc(ROT_TEST_MAX_BUF);
  if(!input) return 1;
  expected = malloc(ROT_TEST_MAX_BUF);
  if(!expected) return 1;
  szrot = malloc(ROT_TEST_MAX_BUF);
  if(!szrot) return 1;

  fin = fopen(argv[1], "r");
  if(!fin) return 1;
  input = fgets(input, ROT_TEST_MAX_BUF, fin);
  if(!input) return 1;
  if(input[strlen(input)-1] == '\n')
    input[strlen(input)-1] = '\0';
  expected = fgets(expected, ROT_TEST_MAX_BUF, fin);
  if(!expected) return 1;
  if(expected[strlen(expected)-1] == '\n')
    expected[strlen(expected)-1] = '\0';
  szrot = fgets(szrot, ROT_TEST_MAX_BUF, fin);
  if(!szrot) return 1;
  nrot = atoi(szrot);
  rc = rot(input, nrot);
  if(rc == 0){
    rc = strcmp(input, expected);
  }
  free(input);
  free(expected);
  free(szrot);
  return rc;
}
