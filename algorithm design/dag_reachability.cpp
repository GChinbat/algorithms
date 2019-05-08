#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007

int n, m;
const int nmax = 25;
vector<int > joint[nmax];
int indeg[nmax];
bool vis[nmax];
vector<int > topo;
int dp[nmax];

void dfs(int u) {
    vis[u] = true;
    for (auto v : joint[u]) {
        if (vis[v]) continue;
        dfs(v);
    }    
    topo.push_back(u);
}

void solve() {
    set<int > dp[nmax];
    for (auto u : topo) {
        dp[u].insert(u);
        for (auto v : joint[u]) {
            for (auto x : dp[v]) {
                dp[u].insert(x);
            }
        }        
    }

    for (int i = 1; i <= n; i ++) {
        cout << i << " : " << dp[i].size() << endl;
    }

}

void solve1() {
    int dp[nmax];
    memset(dp, 0, sizeof dp);
    for (auto u : topo) {
        int uu = u - 1;
        dp[u] |= (1 << uu);
        for (auto v : joint[u]) {
            dp[u] |= dp[v];
        }
    }
    for ( int i = 1;  i<= n; i ++) {
        cout << i << ": " << __builtin_popcount(dp[i]) << endl;
    }
}


signed main() {
    
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    freopen("in", "r", stdin);

    cin >> n >> m;
    while ( m -- ) {
        int u, v;
        cin >> u >> v;
        joint[u].pb(v);
        indeg[v] ++;
    }

    int root = -1;
    for (int i = 1; i <= n; i ++) {
        if (indeg[i] == 0) {
            root= i;
            break;
        }
    }

    dfs(root);    
    
    solve();
    solve1();

    return 0;
}