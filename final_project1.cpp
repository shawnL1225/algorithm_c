#include <bits/stdc++.h>
using namespace std;
int n,m;
char command[1002];
struct student {
    int ID;
    char Name[21];
    int Sid;
    char Class;
    char Email[41];
    int Phone;
};
student tableA[300];
void input()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> tableA[i].ID >> tableA[i].Name >> tableA[i].Sid >> tableA[i].Class >> tableA[i].Email >> tableA[i].Phone;
    }
    for(int i=0;i<m;i++)
    {

    }
}
int main(){
    input();
}