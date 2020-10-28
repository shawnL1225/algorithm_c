#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
long long int prime(long long int n)
{
    long long int max = 0;
    for (long long int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (gcd(i, n / i) > 1)
            {
                continue;
            }
            else
            {
                max = i;
            }
        }
    }
    return max;
}
int main()
{
    long long int n;
    scanf("%lld", &n);
    printf("%lld %lld", prime(n), n / prime(n));
}