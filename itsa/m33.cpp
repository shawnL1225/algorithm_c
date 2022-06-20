#include <iostream>
int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        for(int i=1;i<=n;i++){
            int sum=0;
            for(int j=1;j<=i;j++){
                if(i%j==0){
                    sum+=i;
                }
            }
            if(sum == i) printf("%d ", i);
           
        }
        printf("\n");
    }
}