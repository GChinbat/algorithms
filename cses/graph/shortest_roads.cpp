#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e17+10


typedef pair<int, int > pii;
#define len first
#define node second

const int nmax = (int)2e5 + 10;

int n, m;
vector<pair<int, int >> graph[nmax];
vector<int > dist, out;

void solve() {
    
    priority_queue<pii > Q;
    Q.push(mp(0, 1));
    dist.assign(n + 1, inf);
    out.assign(n + 1, 0);
    dist[1] = 0;

    while (Q.size() ) {
        pii u = Q.top(); Q.pop();
        if (out[u.node]) continue;

        for (auto v : graph[u.node]) {
            if (out[v.node]) continue;
            if (dist[u.node] + v.len < dist[v.node]) {
                dist[v.node] = dist[u.node] + v.len;
                Q.push(mp(-dist[v.node], v.node));
            }     
        }

        out[u.node] = true;
    }

}


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    while ( m -- ) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].pb(mp(w, v));
       // graph[v].pb(mp(w, u));
                
    }

    solve();


    for (int i = 1; i <= n; i ++) {
        cout << dist[i] << " ";
    }
    cout << endl;



    return 0;
}