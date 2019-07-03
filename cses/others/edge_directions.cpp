#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nmax 100005
int n, m;
vector<int > graph[nmax];
int visited[nmax];
vector<int > edge[nmax];


void dfs(int u) {
    visited[u] = 1;
    
    for (auto v : graph[u]) {
        if (visited[v] == 2) continue;
        if (visited[v] == 1) {
            edge[v].pb(u);
            continue;            
        }
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
        graph[v].pb(u);
    }

    memset(visited, 0, sizeof visited);
    for (int i = 1; i <= n; i ++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }
    
    for (int i = 1; i <= n; i ++) {
        for (auto v : edge[i]) {
            cout << i << " " << v << endl;
        }
    }

    return 0;
}