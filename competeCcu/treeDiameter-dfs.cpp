#include <bits/stdc++.h>
#define MAX 300000
using namespace std;
deque<int> F[MAX];
int v[MAX];
void dfs(int x, int d) {
	for (int i = 0; i<F[x].size(); i++) {
		if (v[F[x][i]] == 0) {
			v[F[x][i]] = d + 1;
			dfs(F[x][i], d + 1);
		}
	}
}

int main() {
	int a, b, node, n, max;
	cin >> n;

    for (int i = 0; i<n-1; i++) {
       cin >> a >> b;
        F[a].push_back(b);
        F[b].push_back(a);
    }
    memset(v, 0, sizeof(v));

    dfs(a, 1);
    max = -1;
    for (int i = 1; i <= n; i++) {
        if (v[i] > max) {
            max = v[i];
            node = i;
        }
    }
    memset(v, 0, sizeof(v));
    dfs(node, 1);  
    for (int i = 1; i <= n; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    cout << max-1 ;
	
}