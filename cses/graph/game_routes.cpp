#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mod 1000000007
#define N 100005

int n, m, w[N], d[N];
vector<int > g[N];

void s(int u) {
    w[u] = 1;
    for (auto v : g[u]) {
        if (w[v] == 0) 
            s(v);
        d[u] += d[v];
        d[u] %= mod;
    }    
}

int main() {

    cin >> n >> m;
    while (m -- ) {
        int u, v;
        cin >> u >> v;
        g[v].pb(u);    
    }

    d[1] = 1;
    s(n);
    cout << d[n];

    return 0;
}