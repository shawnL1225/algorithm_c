#include<stdio.h>
int main(){
    double a;
    while(scanf("%lf",&a)!=EOF){
        printf("%.0lf ", a);
        printf("%.0lf ", a*a);
        printf("%.0lf\n", a*a*a);
    }
        
}