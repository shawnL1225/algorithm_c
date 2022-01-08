#include <stdio.h>
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int ind = 1;
        ind <<= 7;
        for(int i=0;i<8;i++){
            n&ind? printf("%d", 1): printf("%d", 0);
            ind >>= 1;
            
        }
        printf("\n");
    }
    
}