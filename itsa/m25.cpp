#include <iostream>
int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        long long sum=0;
        while(n--){
            if(n % 3 == 0) sum +=n;
        }
        printf("%ld\n", sum);
    }
}