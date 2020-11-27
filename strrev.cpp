/* probID: MT2A-3-strrev */
#include <string.h>
// #include <bits/stdc++.h>
// using namespace std;

char s2[100000];
char *strrev(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        s2[strlen(s) - 1 - i] = s[i];
    }
    //for(int i=0;i<strlen(s);i++)cout << s2[i];
    // s2[strlen(s)] = '\0';
    s = s2;
    return s;
}
// #include <stdio.h>
// char *strrev(char *);
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         char tmp[100001];
//         scanf("%s", tmp);
//         printf("%s\n", strrev(tmp));
//     }
//     return 0;
// }
