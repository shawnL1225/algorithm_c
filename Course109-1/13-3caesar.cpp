#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    while(cin >> s){
        for(int i=0;s[i]!='\0';i++)
        {
            if(isalpha(s[i]))
            {
                int ifminus = 0;
                if(isupper(s[i]) && s[i]+n > 'Z' || islower(s[i]) && s[i]+n > 'z') ifminus = -26;
                else if(isupper(s[i]) && s[i]+n < 'A' || islower(s[i]) && s[i]+n < 'a') ifminus = 26;
                    cout << (char)(s[i]+n + ifminus);
            }
            else
                cout << s[i];
           
        }
        cout << ' ';
    }
    
}