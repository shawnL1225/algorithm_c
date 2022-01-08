#include <stdio.h>
char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int main()
{
    int n;
    while (scanf("%d", &n) != EOF){
        int a[100], i = 0, m = 0;

        while (n > 0){
            a[i++] = n % 16;
            n = n / 16;
        }
        for (i = i - 1; i >= 0; i--){
            m = a[i];
            printf("%c", hex[m]);
        }
        printf("\n");
    }
}