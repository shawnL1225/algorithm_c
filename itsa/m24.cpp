#include <iostream>  
int main(){  
    int a,b;  
    while(scanf("%d%d", &a, &b) != EOF){  
        double pay =0;  
        if(a >=121){  
            pay += (a-120)*b*1.66;  
            a=120;  
        }  
        if(a>60){  
            pay += (a-60)*b*1.33;  
            a = 60;  
        }  
        pay += a*b;  
        printf("%.1lf\n", pay);  
  
    }  
      
}