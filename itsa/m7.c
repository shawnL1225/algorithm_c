#include<stdio.h>
int main(){
    int a,b;
    while(scanf("%d",&a,&b)!=EOF){
        printf("%d ", a);
        printf("%.0lf ", a*a);
        printf("%.0lf\n", a*a*a);
    }
        
}