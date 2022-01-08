#include <stdio.h>  
int main(){  
    int a,b;  
    while(scanf("%d%d", &a, &b) != EOF){  
        int sum=0;
        for(int i=a;i<=b;i++){
            sum += i;
        }
        printf("%d\n",sum);
  
    }  
      
}