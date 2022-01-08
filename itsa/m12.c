#include<stdio.h>
int main(){
    int a;
    while(scanf("%d", &a) !=EOF){
      double v = 100 - 30*2.54;
      double s = a*100/v;
      printf("%d\n", (int)s+1);
    }
    
        
}