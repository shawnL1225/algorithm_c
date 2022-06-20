#include <iostream>
int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        int flag =0;
        
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                flag = 1;
                break;
            }
        }
           
        
        if(!flag) printf("YES\n");
        else printf("NO\n");
    }
}