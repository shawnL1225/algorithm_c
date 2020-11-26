#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int m,d;
    cin >> m >> d;
    bool isBig =0;
    if(m < 8 && d%2 == 1) isBig = 1;
    else isBig = 0;

    if(m>=8 && d%2 == 0) isBig = 1;
    else isBig = 0;

    if(m<1 || m>12) {cout << "invalid"; return 0;}
    if(m==2 && d>29)  {cout << "invalid"; return 0;}
    if(isBig && (d>31 || d<1)) {cout << "invalid"; return 0;}
    if(!isBig && (d>30 || d<1) ) {cout << "invalid"; return 0;}

    int sum = m*100 + d;

    if(sum >=122 && sum <=219)         cout << "Aquarius"<<endl;
    else if( sum >= 220 && sum <= 320) cout << "Pisces"<<endl;
    else if( sum >= 321 && sum <= 420) cout << "Aries"<<endl;
    else if( sum >= 421 && sum <= 520) cout << "Taurus"<<endl;
    else if( sum >= 521 && sum <= 621) cout << "Gemini"<<endl;
    else if( sum >= 621 && sum <= 722) cout << "Cancer"<<endl;
    else if( sum >= 723 && sum <= 822) cout << "Leo"<<endl;
    else if( sum >= 823 && sum <= 922)  cout << "Virgo"<<endl;
    else if( sum >= 923 && sum <= 1022) cout << "Libra"<<endl;
    else if( sum >= 1023 && sum <= 1122) cout << "Scorpio"<<endl;
    else if( sum >= 1123 && sum <= 1222) cout << "Sagittarius"<<endl;
    else if( (sum >= 1223 && sum) <= 1231  || (sum >=101 && sum <=121))  cout << "Capricorn"<<endl;

}
