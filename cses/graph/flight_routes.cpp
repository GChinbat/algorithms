#include <bits/stdc++.h>
using namespace std;
#define nmax 200005

#define mp make_pair
#define pb push_back
#define cost first
#define node second
#define int long long

typedef pair<int, int > pii;

vector<pii > graph[nmax];
int n, m, k;

vector<int > outs[nmax];


void dijkstra() {
    priority_queue <pii > Q;
    
    Q.push(mp(0, 1));
    while ( Q.size()) {
        pii toop = Q.top(); Q.pop();
        
        int u = toop.node;
        int dist = -toop.cost;
        if (outs[u].size() >= k) continue;
        for (auto p : graph[u]) {
            int v = p.node;
            int c = p.cost;
            Q.push(mp(-(dist + c), v));
        }
        
        if (outs[u].size() < k) {
            outs[u].pb(dist);
        }
        if (outs[n].size() == k) {
            break;
        }
    }
    
    sort(outs[n].begin(), outs[n].end());

    for (auto co : outs[n]) {
        cout << co << " ";
    }
    cout << endl;

}



signed main() {

    cin >> n >> m >> k;
    while ( m -- ) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].pb(mp(c,v));
    }
       
    dijkstra();
        
    



    return 0;
}