#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> odd;
    vector<int> even;
    int n,num;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        if(num%2)
            odd.push_back(num);
        else
            even.push_back(num);
    }

    for(int i=0;i<odd.size();i++)
        cout << odd[i] <<' ';
    cout << '\n';
    for(int i=0;i<even.size();i++)
        cout << even[i] <<' ';


}