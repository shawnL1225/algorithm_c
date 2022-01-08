#include<stdio.h>
int main(){
    int n;
    char op;
    int a,b,c,d;

    scanf("%d\n", &n);
    while(n--){
        scanf("\n%c",&op);
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(op == '+'){
            printf("%d %d\n",a+c,b+d);
        }else if(op == '-'){
            printf("%d %d\n",a-c,b-d);
        }else if(op == '*'){
            printf("%d %d\n",(a*c-b*d), (b*c+a*d));
        }else if(op == '/'){
            int x = c*c+d*d;
            printf("%d %d\n",(a*c+b*d)/x, (b*c+a*d)/x);
        }

    }
}