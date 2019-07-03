#include <bits/stdc++.h>
using namespace std;
#define nmax 100005
#define pb push_back


int n, m, indeg[nmax], outdeg[nmax];
vector<int > graph[nmax], euler_path;


void dfs(int u) {
    
    while (graph[u].size()) {
        int v = graph[u].back();
        graph[u].pop_back();
        dfs(v);
    }

    euler_path.pb(u);
}


bool is_edges_deleted() {
    for (int i = 1; i <= n; i ++) {
        if (graph[i].size() > 0) return false;
    }
    return true;
}

void print_path() {
        
    reverse(euler_path.begin(), euler_path.end());
    euler_path.pop_back();
    
            
    int fin = euler_path.size() - 1;
    for (int i = 0; i < euler_path.size() - 1; i ++) {
        if (euler_path[i] == n && euler_path[i + 1] == 1) {
            fin = i;                       
        }
    }

    for (int i = fin + 1; i <euler_path.size(); i ++) {
        cout << euler_path[i] << " ";
    }
    for (int i = 0; i <= fin; i ++) {
        cout << euler_path[i] << " ";    
    }
    cout << endl;


}




signed main() {
    
    cin >> n >> m;
    while ( m -- ) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        indeg[v] ++;
        outdeg[u] ++;
    }
    
    bool has_euler_path = true;
    if (indeg[1] + 1 != outdeg[1]) {
        has_euler_path = false;    
    }
    if (indeg[n] != outdeg[n] + 1) {
        has_euler_path = false;
    }

    for (int i = 2; i < n ; i ++) {
        if (indeg[i] != outdeg[i]) {
            has_euler_path = false;
        }
    }



    if (has_euler_path) {
        graph[n].pb(1);
        dfs(1);
        bool ok = is_edges_deleted();
        if (ok) {
            print_path();
            return 0;
        }
    } 
    
    cout << "IMPOSSIBLE" << endl;
   
    return 0;
}