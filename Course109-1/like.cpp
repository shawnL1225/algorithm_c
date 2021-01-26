#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "%APP12%APP14"; 
    string tableS = "there APP12 isAPP12///APP14/";
    int len = s.length();
    int tlen = tableS.length();
    for(int tablei=0, fi=0; fi<len && tablei<tlen; )
    {
        // cout << fi <<endl;
        // cout << tablei <<endl;
        if(s[fi] == '%'){
            int iter = fi+1;
            while((s[iter] != '%') && iter<len) iter++;
            int substr_len = iter - (fi+1);
            if(substr_len)
            {
                string substr = s.substr(fi+1,substr_len);
                // cout << substr <<endl;
                tablei = tableS.find(substr,tablei);
                if(tablei>=0)
                {
                    fi += substr_len+1 ;
                    tablei += substr_len;
                }
                else
                    break;
            }
            else{ //finish
                cout << "success !"<<endl;
                break;
            }
        }
        // else if(s[fi] == '_'){
        //     if(tablei<tableS.length())
        //     {
        //         tablei++;
        //         fi++;
        //     }
        //     else
        //         break;
        // }
        else{
            if(tableS[tablei] == s[fi])
            {
                tablei++;
                fi++;
            }
            else
                break;
        }

        if(tablei == tableS.length() && fi+1 >= s.length())
            cout << "success !"<<endl;
        
    }
    cout << "endl";

}