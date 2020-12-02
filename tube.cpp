#include <iostream>

using namespace std;
char arr[101][101];
int high[101][101];
int n,m;

void neighbor(int y,int x)
{

    if(arr[y][x] == '-')
    {
        arr[y][x] = '!';
        if(x>0 && high[y][x-1]!='!' && high[y][x-1] <= high[y][x] &&  (arr[y][x-1]=='-' || arr[y][x-1]=='+')) {neighbor(y,x-1);}
        if( x+1<m && high[y][x+1]!='!' && high[y][x+1] <= high[y][x] &&(arr[y][x+1]=='-' || arr[y][x+1]=='+')){neighbor(y,x+1);}

    }
    else if(arr[y][x] == '+')
    {
        arr[y][x] = '!';
        if( x>0 && high[y][x-1]!='!' && high[y][x-1] <= high[y][x] && (arr[y][x-1]=='-' || arr[y][x-1]=='+')){neighbor(y,x-1);}
        if(x+1<m && high[y][x+1]!='!' && high[y][x+1] <= high[y][x] && (arr[y][x+1]=='-' || arr[y][x+1]=='+')){neighbor(y,x+1);}
        if(y>0 && high[y-1][x]!='!' && high[y-1][x] <= high[y][x] && (arr[y-1][x]=='+' || arr[y-1][x]=='|')){neighbor(y-1,x);}
        if(y+1<n && high[y+1][x]!='!' && high[y+1][x] <= high[y][x] && (arr[y+1][x]=='+' || arr[y+1][x]=='|')){neighbor(y+1,x);}
    }
    else if(arr[y][x] == '|')
    {
        arr[y][x] = '!';
        if(y>0 && high[y-1][x]!='!' && high[y-1][x] <= high[y][x] &&  (arr[y-1][x]=='+' || arr[y-1][x]=='|')){neighbor(y-1,x);}
        if(y+1<n && high[y+1][x]!='!' && high[y+1][x] <= high[y][x] && (arr[y+1][x]=='+' || arr[y+1][x]=='|')){neighbor(y+1,x);}

    }


}
int main()
{

    cin >> n>>m;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> high[i][j];

    int oy,ox,dy,dx;
    cin >> oy>>ox>>dy>>dx;

    neighbor(oy,ox);
    if(arr[dy][dx]=='!') cout << "YES";
    else cout << "NO";

//    cout << endl;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++)
//            cout << arr[i][j] <<' ';
//        cout << endl;
//    }

    return 0;
}
