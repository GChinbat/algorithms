#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nmax 100005
#define pb push_back
#define mp make_pair

int n, m;
int k[nmax];
vector<int > graph[nmax], g[nmax], ng[nmax];

vector<int > topo;
int visited[nmax];

void dfs1(int u) {
    visited[u] = true;
    for (auto v : g[u]) {
        if (visited[v]) continue;
        dfs1(v);
    }    
    topo.pb(u);
    return ;
}


void dfs2(int u, int gid) {
    visited[u] = gid;
    for (auto v : graph[u]) {
        if (visited[v]) continue;
        dfs2(v, gid);
    }
}

map<int, int > groupsum;
map<pair<int, int >, bool > has;

int dp[nmax];

int dfs3(int u) {   
    if (dp[u] != -1) return dp[u];
    int mx = 0;
    for (auto v : ng[u]) {
        mx = max(mx, dfs3(v) + groupsum[v]);
    }
    return dp[u] = mx;
}


signed main() {
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++) {
        cin >> k[i];
    }

    while ( m -- ) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        g[v].pb(u);
    }

    memset(visited, 0, sizeof visited);

    for (int i = 1; i <= n; i ++) {
        if (visited[i] != true) {
            dfs1(i);    
        }
    }

    reverse(topo.begin(), topo.end());
    memset(visited, 0, sizeof visited);
    int group_id = 1;
    
    for (auto u : topo) {
        if (visited[u] == 0) {
            dfs2(u, group_id ++);
        }            
    }

    for (int i = 1; i <= n; i ++) {
        groupsum[visited[i]] += k[i];
        int u = i;
        int gu = visited[u];
        for (auto v : graph[u]) {
            int gv = visited[v];
            if (gu == gv) continue;
            if (has[mp(gu, gv)] == false) {
                ng[gu].pb(gv);
                has[mp(gu, gv)] = true;
            }           
        }
    }

    int ans = 0;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i < group_id; i ++) {
        int tmp_sum = dfs3(i) + groupsum[i];
        ans = max(ans, tmp_sum);
    }
    
    cout << ans << endl;

    return 0;
}