#include <bits/stdc++.h>
using namespace std;

#define nmax 100005
#define pb push_back

int n, m, deg[nmax];
vector<int > graph[nmax], euler_cycle;


void dfs(int u) {
    
    while (graph[u].size()) {
        int v = graph[u].back();
        graph[u].pop_back();
        for (auto& g : graph[v]) {
            if (g == u) {
                swap(graph[v].back(), g);
                graph[v].pop_back();
                break;
            }    
        }
        dfs(v);
    }

    euler_cycle.pb(u);
}

bool all_edges_deleted() {
    
    for (int i = 1; i <= n; i ++) {
        if (graph[i].size() > 0) {
            return false;
        }
    }
    return true;
}


signed main() {
    
    cin >> n >> m;
    while ( m -- ) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
        deg[u] ++;
        deg[v] ++;    
    }

    bool has_euler_cycle = true;
    for (int i = 1; i <= n; i ++) {
        if (deg[i] & 1) {
            has_euler_cycle = false;
            break;    
        }
     }
    


    if (has_euler_cycle) {
        dfs(1);

        bool ok = all_edges_deleted();
        if (ok) {
            for (auto u : euler_cycle) {
                cout << u << " ";
            }
            cout << endl;
            return 0;
        }
       
    } 
    
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}