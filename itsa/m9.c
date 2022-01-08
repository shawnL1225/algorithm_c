#include<stdio.h>
int main(){
    int a;
    while(scanf("%d", &a) !=EOF){
        if(a>31) printf("Value of more than 31\n");
        else{
            printf("%d\n", 1<<a);
        }
    }
    
        
}