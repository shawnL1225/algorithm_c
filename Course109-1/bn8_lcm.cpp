#include <bits/stdc++.h>

using namespace std;
vector<long long int> vec;
int main()
{
    long long int n, start = 1;
    cin >> n;
    long long int a = n, b = 1, n2 = n;

    for (int i = 2; i * i <= n2; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            start *= i;

            if (n + start > a + b)
            {
                cout << a << ' ' << b;
                return 0;
            }

            if (__gcd(n, start) == 1)
            {
                a = n;
                b = start;
            }
        }
    }

    return 0;
}
