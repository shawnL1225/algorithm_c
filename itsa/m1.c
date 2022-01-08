#include<stdio.h>
int main(){
    double top,down,h;
    while(scanf("%lf%lf%lf", &top,&down,&h) != EOF)
        printf("Trapezoid area:%.1lf\n", (top+down)*h/2);
}