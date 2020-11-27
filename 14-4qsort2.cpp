#include <bits/stdc++.h>
using namespace std;

 int comp(const void* a,const void* b)
 {
    return strcmp((char*)a,(char*)b);
 }


char s[100005][105];

// string ss[10005];
int main(){
    
    // for(int i=0;getline(cin,ss[i]) ;i++)

    int i=0;
    while(fgets(s[i],105,stdin))
    {
        i++;
    }
    qsort(s,i,sizeof(s[0]),comp);

    // cout << i<<endl;
    for(int j=0;j<i;j++)
    {
        cout << s[j];
    }
}
