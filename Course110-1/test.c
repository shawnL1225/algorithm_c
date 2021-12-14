	
#include<stdio.h>
int main(){
 
    float money;
    float day;
    scanf("%f %f", &money, &day);
 
    for(int i =1; i<=day; ++i){
        money=money*1.00054;
    }
    printf("%f\n", money);
}