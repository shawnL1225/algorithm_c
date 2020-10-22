#include <stdio.h>

int main() {
    int sum , feet , tails;
    int c , r , s;
    scanf("%d%d%d", &sum, &feet, &tails);
    tails == c + r;
    sum == c + r + s;
    feet == c * 2 + r * 4 + s * 8;
    s = sum - tails;
    r = (feet - sum * 2 - s * 6) / 2;
    c = sum - s - r;
    printf("%d\n%d\n%d\n",c,r,s);
    return 0;
}
