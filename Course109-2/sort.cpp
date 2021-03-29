#include<bits/stdc++.h>
using namespace std;
struct person{
    int age;
    string name;
    int weight;
};

bool comp(person a, person b){
    if(a.name != b.name) return a.name < b.name;
    if(a.age != b.age) return a.age > b.age;
    return a.weight > b.weight;
}
int main(){
    int n;
    cin >> n;
    person list[n];
    for(int i=0;i<n;i++)
    {
        cin >> list[i].name >> list[i].age >> list[i].weight;
    }
    sort(list,list+n,comp);

    for(int i=0;i<n;i++){
        cout << list[i].name << ' '<<list[i].age <<' '<< list[i].weight<<endl;
    }
}