#include<stdio.h>

typedef long long lint;
int main(){
    double n;
    while(scanf("%ld",&n) != EOF)
        printf("%.1lf\n", n*1.6);


    return 0;
}