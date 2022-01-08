#include<stdio.h>  
int main(){  
    double down,h;  
    while(scanf("%lf%lf",&down,&h) != EOF)  
        printf("%.1lf\n", (down)*h/2);  
}  