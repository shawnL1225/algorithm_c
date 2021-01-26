#include <set>
#include <iostream>
using namespace std;
int main(){
    set<int> s;
    int n;
    cin >> n;

    int num;
    for(int i=0;i<n;i++){
        cin >> num;
         s.insert(num);
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> num;
        if(s.count(num)) cout << "Found!"<<endl;
        else cout << "not Found"<<endl;
    }
       
}