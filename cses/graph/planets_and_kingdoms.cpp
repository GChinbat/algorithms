#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nmax 100005

int n, m;
vector<int > graph[2][nmax], topo, pre;

int vis[nmax] = {0};
int flag = 1;

void dfs(int u, int id) {
    vis[u] = flag;
    for (auto v : graph[id][u]) {
        if (!vis[v])
            dfs(v, id);
    }
    topo.pb(u);
}





signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);    

    cin >> n >> m;
    while ( m -- ) {
        int u, v;
        cin >> u >> v;
        graph[0][u].pb(v);
        graph[1][v].pb(u);
    }

    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            dfs(i, 1);
        }
    }

    reverse(topo.begin(), topo.end());
    pre = topo;
    topo.clear();

    memset(vis, 0, sizeof vis);
    flag = 0;
    for (auto u : pre) {
        if (vis[u] == 0) {
            flag ++;
            dfs(u, 0);
        }
    } 

    cout << flag << endl;
    for (int i = 1; i <= n; i ++) {
        cout << vis[i] << " ";
    }
    cout << endl;


    return 0;
}