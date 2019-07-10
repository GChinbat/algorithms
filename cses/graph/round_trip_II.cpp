#include <bits/stdc++.h>
using namespace std;

#define nmax 100005
#define pb push_back

int n, m;
vector<int > graph[nmax];
int visited[nmax], parent[nmax];

bool has_cycle;

void get_cycle(int x, int s) {
    
    vector<int > path;
    path.pb(s);
    while(x != s) {    
        path.pb(x);
        x = parent[x];
    }
    path.pb(s);
    cout << path.size() << endl;
    reverse(path.begin(), path.end());
    for (auto u : path) {
        cout << u << " ";
    }
    cout << endl;
    
}


void dfs(int u) {
    if (has_cycle) return ;
    visited[u] = 1;
    for (auto v : graph[u]) {
        if (has_cycle) return ;
        if (visited[v] == 2) continue;
        if (visited[v] == 1) {
            get_cycle(u, v);
            has_cycle = true;
            return ;
        }

        parent[v] = u;
        dfs(v);
    }
    visited[u] = 2;
}




signed main() {

    cin >> n >> m;
    while ( m -- ) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
    }    
    
    memset(visited, 0, sizeof visited);
    memset(parent, -1, sizeof parent);
    has_cycle = false;
    for (int i = 1; i <= n; i ++) {
        if (has_cycle) break;
        if (visited[i] == 0) {
            dfs(i);
        }                 
    }

    if (has_cycle == false) {
        cout << "IMPOSSIBLE" << endl;
    }



    return 0;
}