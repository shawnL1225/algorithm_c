#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
  
//   printf("%s\n",argv[0]);
  int len = strlen(argv[1]);
  for(int i=0;i<len;i++)
  {
    printf("%c",argv[1][len-i-1]);
  }
  return 0;
}