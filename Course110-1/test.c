#include<stdio.h>
void swapStrings(char** a, char** b){
    char *temp = *a;
    *a = *b;
    *b = temp;
    
}
int main(){
    char* x = "Hello";
    char* y = "world";
    swapStrings(&x, &y);
    printf("%s" , x);
}
