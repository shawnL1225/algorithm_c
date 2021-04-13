#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    set<char> vow;
    vow.insert('A');vow.insert('a');
    vow.insert('E');vow.insert('e');
    vow.insert('I');vow.insert('i');
    vow.insert('O');vow.insert('o');
    vow.insert('U');vow.insert('u');
    vow.insert('Y');vow.insert('y');
    for(int i=0;i<s.length();i++){
        if(vow.count(s[i]) == 0){
            cout << '.'<< (char)tolower(s[i]);
        }
    }
}