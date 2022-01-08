#include <stdio.h>
int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        long long sum=1;
        for(int i=2;i<=n;i++){
            sum*=i;
        }
        printf("%ld\n", sum);
    }
}