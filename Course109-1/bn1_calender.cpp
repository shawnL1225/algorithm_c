#include <iostream>
using namespace std;
int main()
{
    int y,m,w;
    bool isBig, isMoon=0;
    cin >> y >> m >> w;

    if(m < 8 && m%2 == 1) isBig = 1;
    else if(m<8 && m%2==0) isBig = 0;

    if(m>=8 && m%2 == 0) isBig = 1;
    else if(m>=8 && m%2==1) isBig = 0;

    if(y%4 == 0) isMoon = 1;

    if(m<1 || m>12) {cout << "invalid"; return 0;}
    if(w<1 || w>7) {cout << "invalid"; return 0;}

    int myDay;

    if(isBig) myDay = 31;
    else myDay = 30;


    if(m==2 && isMoon) myDay = 29;
    else if(m==2 && !isMoon) myDay = 28;




    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================\n");

    for(int i=0;i<w%7;i++)
        printf("   ");

    for(int i=1;i<=myDay;i++)
    {
        printf("%3d", i);
        if((i+w) %7==0) printf("\n");
    }
    if((myDay+w)%7!=0) printf("\n");

    printf("=====================\n");
}
