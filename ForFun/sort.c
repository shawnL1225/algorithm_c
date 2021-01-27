#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int rev = 0, isnumV = 0;
char s[5000][1050];
int comp(const void* a,const void* b)
{
    if(isnumV)
    {
        int a_int = atoi((char*)a);
        int b_int = atoi((char*)b);
        if(a_int < b_int ) return -1;
        else if(a_int == b_int ) return 0;
        else  return 1;
    }
    else
        return strcmp((char*)a,(char*)b);
}

int main(int argc, char *argv[]) {
    // printf("We have %d arguments:\n", argc);
    
    
    for (int i = 0; i < argc; i++) {
        if(argv[i][1] == 'n') isnumV = 1;
        if(argv[i][1] == 'r') rev = 1;
        // printf("argv: %s\n",argv[i]);
    }

    int i=0;
    while(fgets(s[i],1050,stdin))
    {
        i++;
    }
    qsort(s,i,sizeof(s[0]),comp);

    for(int j=0;j<i;j++)
    {
        if(rev)
            printf("%s",s[i-j-1]);
        else
            printf("%s",s[j]);
    }

  return 0;
}