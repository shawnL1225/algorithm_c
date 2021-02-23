#include <bits/stdc++.h>
using namespace std;
int main()
{
    char num[200];
    char c;
    int sum=0;
    while(1)
    {
        c = getchar();
        if(c == EOF) break;
        if(isdigit(c))
        {
            int j=0;
            while(isdigit(c))
            {
                num[j] = c;
                j++;
                c = getchar();
            }
            num[j] = '\0';
            int i = atoi(num);
            sum+=i;
            
        }
        
    }
    cout << sum <<endl;
}