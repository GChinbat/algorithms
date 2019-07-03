#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define inf (int)1e18+7
#define mod 1000000007
const int nmax = (int) 1e5 + 10;

int n;
vector<int > graph[nmax];
vector<int > tree[nmax];

bool vis[nmax];

void dfs(int u) {
    vis[u] = true;
    for (auto v: graph[u]) {
        if (vis[v]) continue;
        tree[u].push_back(v);
        dfs(v);
    }   
}

int dp[nmax][2];

void dfs1(int u) {
    
    dp[u][0] = 1;
    dp[u][1] = 1;
    for (auto v : tree[u]) {
        dfs1(v);
        dp[u][0] *= (dp[v][0] + dp[v][1]) % mod;
        dp[u][0] %= mod;
        dp[u][1] *= dp[v][0];
        dp[u][1] %= mod;     
    }
       
}            
                     
signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int m = n - 1;
    while(m -- ) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);
    dfs1(1);

    cout << (dp[1][0] + dp[1][1]) % mod << endl;

    return 0;
}
