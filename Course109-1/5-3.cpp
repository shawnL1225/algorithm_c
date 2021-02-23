#include<iostream>
#include<stdio.h>
using namespace std;
int n, m;

void sepLine()
{
    cout << "+-----+";
    for(int i=0;i<m;i++)
        cout<<"----";
    cout << "--+\n";
}
void firstLine()
{
    printf("|     |");
    for(int i=1;i<=m;i++)
        printf("%4d",i);
    printf("  |\n");
}

void content()
{
    int i = 1;
    for(;i <=n;i++)
    {
        printf("|%3d  |",i);
        int j = 1;
        for(;j<=m;j++)
        {
            printf("%4d",i*j);
        }
        printf("  |\n");
    }
}
int main()
{
    cin >> n >> m;
    sepLine();
    firstLine();
    sepLine();
    content();
    sepLine();

    return 0;

}