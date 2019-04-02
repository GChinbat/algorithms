#include <bits/stdc++.h>
using namespace std;

const int emax = (int)1e7 + 10;
const int nmax = (int)1e6 + 10;

struct Edge {
    int u, v, w, pre;
    void init (int _u, int _v, int _w, int _pre) {
        u = _u; v = _v; w = _w; pre = _pre;
    }
} edge[emax];

int lastpos[nmax], cnt;

void add_edge(int u, int v, int w) {
    edge[cnt].init(u, v, w, lastpos[u]); lastpos[u] = cnt ++;
    edge[cnt].init(v, u, 0, lastpos[v]); lastpos[v] = cnt ++;
}

int source, target;

vector<int > bfs() {
    vector<int > parent(target + 1, -1);
    vector<int > dist(target + 1, -1);
    queue<int > que;
    que.push(source);
    dist[source] = 0;
    while( que.size() ) {
        int u = que.front(); que.pop();
        for (int i = lastpos[u]; i != -1; i = edge[i].pre) {
            if ( dist[edge[i].v] > -1) continue;
            if ( edge[i].w < 1) continue;
            dist[edge[i].v] = dist[u] + 1;
            que.push(edge[i].v);
            parent[edge[i].v] = i;
        }
    }
    if (dist[target] > -1) {
        return parent;
    } return vector<int> ();
}

int flowing(int u, int ff, vector<int > * par) {
    if ( u == source) return ff;
    int i = (*par).at(u);
    int j = i ^ 1;
    int flow = flowing(edge[i].u, min(edge[i].w, ff), par);
    edge[i].w -= flow;
    edge[j].w += flow;
    return flow;
}

int get_max_flow() {
    int max_flow = 0;
    while(true) {
        vector<int > parent = bfs();
        if ( parent.size() == 0) break;
        for (int j = lastpos[target]; j != -1; j = edge[j].pre) {
            int i = j ^ 1;
            if ( edge[i].w < 1) continue;
            int flow = flowing(edge[i].u, edge[i].w, &parent);
            edge[i].w -= flow;
            edge[j].w += flow;
            max_flow += flow;
        }
    }
    return max_flow;
}


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    cnt = 0;
    memset(lastpos, -1, sizeof lastpos);
    source = 0;
    target = n + m + 1;
    
    for (int u = 1; u <= n; u ++) {
        for (int v = 1; v <= m; v ++) {
            add_edge(u, v + n, 1);  
        }
    }
    
    
    for (int j  = 1; j <= m; j ++) {
        add_edge(n + j, target, 1);
    }
    
    
    int ans = get_max_flow();
    cout << "0 :: " << ans << endl;
    
    for (int i = 1; i <= n; i ++) {
        add_edge(source, i, 1);
        int ans = get_max_flow();
        cout << i << " :: " << ans << endl;    
    }
        
        
    return 0;
}