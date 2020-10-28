#include <iostream>
using namespace std;


int main()
{
    char c;
    while(cin >> c){
        if(c == cin.eof()) break;
        cout << c << endl;
    }
    cout << "out!";

    return 0;
}