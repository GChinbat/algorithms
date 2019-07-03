#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7

const int nmax = (int)2e5 + 10;
int n;
vector<int > tree[nmax];
int farnode = 0;
int fardist = 0;
int deep = 0;

void dfs1(int u, int p) {

    for (auto v : tree[u]) {
        if ( v == p) continue;
        deep ++;
        dfs1(v, u);
        deep --;
    }

    if (fardist < deep) {
        fardist = deep;
        farnode = u;
    }
        
}

vector<int > path, diam;

void dfs2(int u, int p) {
    path.pb(u);
    for (auto v : tree[u]) {
        if ( v == p) continue;
        dfs2(v, u);
    }
    if (path.size() > diam.size()) {
        diam = path;    
    }
    path.pop_back();
}

int dist[nmax];


void bfs() {
    
    queue<int > Q;
    for (auto u : diam) {
        Q.push(u);
    }

    while(Q.size()) {
        int u = Q.front(); Q.pop();
        for (auto v : tree[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            Q.push(v);   
        }
    }

}


signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int m = n - 1;
    while (m -- ) {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    dfs1(1, 0);
    dfs2(farnode, 0);

    memset(dist, -1, sizeof dist);
    for (int i = 0; i < diam.size(); i ++) {
        int u = diam[i];
        dist[u] = i;            
    }
    reverse(diam.begin(), diam.end());
    for (int i = 0;  i< diam.size(); i ++) {
        int u = diam[i];
        dist[u] = max(dist[u], i);
    }
    
    bfs();

    for (int i = 1; i <= n; i ++) {
        cout << dist[i] << " ";
    }

    return 0;
}