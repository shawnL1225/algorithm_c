#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)


void solve() {
    int a, b;
    string s;
    cin >> a >> b >> s;
    for (char ch : s)
    {
        if (ch == '0')
            a--;
        else if (ch == '1')
            b--;
    }
    int n = (int) s.length();
    bool valid = true;
    for (int i = 0; i < n / 2; i++)
    {
        int j = n - i - 1;
        if (s[j] != '?' && s[i] != '?')
        {
            if (s[j] != s[i])
                valid = false;
            continue;
        }
        if (s[i] == '?' && s[j] == '?')
        {
            continue;
        }
        else if (s[i] == '?')
        {
            s[i] = s[j];
            if (s[i] == '0')
                a--;
            else
                b--;
        }
        else
        {
            s[j] = s[i];
            if (s[i] == '0')
                a--;
            else
                b--;
        }
    }
    for (int i = 0; i < n / 2; i++)
    {
        int j = n - i - 1;
        if (s[i] == '?')
        {
            if (a > b)
            {
                a -= 2;
                s[i] = s[j] = '0';
            }
            else
            {
                b -= 2;
                s[i] = s[j] = '1';
            }
        }
    }
    if ((n & 1) && s[n / 2] == '?')
    {
        if (a > b)
        {
            a--;
            s[n / 2] = '0';
        }
        else
        {
            b--;
            s[n / 2] = '1';
        }
    }
    if (a < 0 || b < 0)
        valid = false;
    if (!valid)
        cout << "-1\n";
    else
        cout << s << "\n";
    
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}