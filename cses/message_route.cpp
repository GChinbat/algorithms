#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10

const int nmax = (int)1e5 + 10;
int n, m;
vector<int > graph[nmax];
vector<int > dist, parent;


bool solve() {
    
    int source = 1;
    queue<int > Q;
    
    dist.assign(n + 1, -1);
    parent.assign(n + 1, -1);

    Q.push(source);
    dist[source] = 0;

    while ( Q.size() ) {
        int u = Q.front(); Q.pop();
        for (auto& v : graph[u]) {
            if ( dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            parent[v] = u;
            Q.push(v);                    
        }
    }
    return dist[n] != -1;
}



signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    while ( m -- ) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);  
    }

    bool res = solve();
    if (!res) {
        puts ( "IMPOSSIBLE");
    }
    else {
        cout << dist[n] + 1 << endl;
        vector<int > path;
        int l = n;
        while (l != -1) {
            path.pb(l);
            l = parent[l];    
        }
        reverse(path.begin(), path.end());
        for (auto& a : path) {
            cout << a << " ";    
        } cout << endl;
    }

    





    return 0;
}