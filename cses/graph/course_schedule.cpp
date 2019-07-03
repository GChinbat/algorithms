#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nmax 100050
int n, m;
vector<int > graph[nmax];
int ins[nmax];
int visited[nmax];

vector<int > topo;
bool cycle = false;

void dfs(int u) {
    if (cycle) return ;
    visited[u] = 1;
    for (auto v : graph[u]) {
        if (visited[v] == 1) {
           cycle = true;
           return ; 
        }
        if (visited[v] == 2) continue;
        dfs(v);
    }
    visited[u] = 2;
    topo.pb(u);    
}


signed main() {

    cin >> n >> m;
    while ( m -- ) {
        int u, v;
        cin >> u >> v;
        graph[v].pb(u);
        ins[u] ++;
    }

   
    int source = 0;
    for (int i = 1; i <= n; i ++) {
        if (ins[i] == 0) {
            graph[source].pb(i);
        }
    }

    dfs(source);

    
    if (topo.size() != n + 1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for (auto v : topo) {
            if (v == 0) continue;
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}