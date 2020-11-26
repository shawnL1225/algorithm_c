/* probID: MT2A-3-strrev */
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

char *strrev(char *s)
{
    char s2[100000];
    for(int i=0;i<strlen(s);i++)
    {
        s2[strlen(s)-1-i] = s[i];
    }
    //for(int i=0;i<strlen(s);i++)cout << s2[i];
    s2[strlen(s)] = '\0';
    s=s2;
    return s;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char tmp[100001];
        cin>>tmp;
        //cout<<tmp<<endl;
        cout<<strrev(tmp)<<endl;
    }
}

