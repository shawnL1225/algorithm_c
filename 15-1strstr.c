/*  probID: 15-1-StringString  */
#include <stdio.h>
#include <string.h>

char *StringString(const char*, const char*);

int main()
{
    char str[10000], substr[10000];
    char *ptr;
    
    fgets(str, 10000, stdin);
    fgets(substr, 10000, stdin);
    
    if(substr[strlen(substr) - 1] == '\n')
        substr[strlen(substr) - 1] = '\0';
    
    ptr = StringString(str, substr);
    
    while(ptr)
    {
        printf("%s", ptr);
        
        ptr += strlen(substr);
        ptr = StringString(ptr, substr);
    }
    
    return 0;
}
char *StringString( const char *str, const char *substr )
{
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i] != substr[0]) continue;
        int j=0;
        int sublen = strlen(substr);
        // printf("%d",i);
        for(;j<sublen && i+j < len;j++)
        {
            if(str[i+j]!=substr[j]) break;
            // printf("^");
        }
        
        if(j == strlen(substr)) return (char*)(str+i);
    }
    return NULL;
}