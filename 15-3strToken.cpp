#include <bits/stdc++.h>
using namespace std;
char s[1900000000];
int main(){
    
    while(fgets(s,1900000000,stdin))
    {
        char *ptr = strtok(s," \t");
        while(ptr)
        {
            int j =0;
            int len = strlen(ptr);
            while(j<len)
            {
                if(isalpha(ptr[j]) || ptr[j] == '_')
                {
                    int start=j;
                    printf("\"");
                    for(;j<len;j++)
                    {
                        if(!(isalpha(ptr[j]) || ptr[j] == '_' || isdigit(ptr[j])))break;
                    }
                    for(int i=start;i<j;i++)
                        printf("%c",ptr[i]);
                    printf("\"\n");
                    
                    
                }
                else
                {
                    printf("%c\n",ptr[j]);
                    j++;
                }
                
                
            }
            
            
            ptr = strtok(NULL, " \t");
        }
    }

}