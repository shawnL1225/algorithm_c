#include <stdio.h>
int main(){
    
    int n;
    while(scanf("%d",&n) != EOF){
        if(n<3) printf("Winter\n");
        else if(n<6 ) printf("Spring\n");
        else if(n<9 ) printf("Summer\n");
        else if(n<12 ) printf("Autumn\n");
        else if(n<13 ) printf("Winter\n");
    }
    


    return 0;
}