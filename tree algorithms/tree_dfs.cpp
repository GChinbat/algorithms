#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7
#define pb push_back
#define mp make_pair

const int nmax = (int)1e5 + 10;
int n;
vector<int > joint[nmax];

void dfs(int u, int p) {
    
    for (auto v : joint[u]) {
        if (u == p) continue;
        dfs(v, u);
    }

}

int cnt[nmax];

void dfs1(int u, int p) {
    cnt[u] = 1;
    for (auto v : joint[u]) {
        if ( u == p) continue;
        dfs1(v, u);
        cnt[v] += cnt[u];
    }
}


signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    int mm = n - 1;
    while ( mm -- ) {
        int u, v;
        cin >> u >> v;
        joint[u].pb(v);
        joint[v].pb(u);
    }
    
    dfs(1, 0);
    
    return 0;
}