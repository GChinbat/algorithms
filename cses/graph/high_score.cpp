#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18

int n, m;

struct Edge {
    int from, to, score;
} edge;

vector<Edge > edges;
vector<int > dist;

vector<int > graph[5000];

bool is_reach_n, visited[5000], ok[5000];


void dfs(int u, int tar) {
    if (is_reach_n) return ;
    visited[u] = true;
    if (u == tar) {
        is_reach_n = true;
        return ;
    }
    for (auto v : graph[u]) {
        if (visited[v]) continue;
        dfs(v, tar);
    }    
    return ;
}

int bellman_ford() {

    dist.assign(n + 1, -inf);
    dist[1] = 0;

    int m = n - 1;
    while (m -- ) {
        for (auto e : edges) {
            dist[e.to] = max(dist[e.to], dist[e.from] == inf ? dist[e.from] : dist[e.from] + e.score);
        }
    }
    
    for (auto e : edges) {
        int last = dist[e.to];
        dist[e.to] = max(dist[e.to], dist[e.from] == inf ? dist[e.from] : dist[e.from] + e.score);
        if (dist[e.to] > last) {
            is_reach_n = false;
            memset(visited, 0, sizeof visited);
            dfs(e.to, n);   
            if (is_reach_n) {
                is_reach_n = false;
                memset(visited, 0, sizeof visited);
                dfs(1, e.to);
                if (is_reach_n) {
                    return -1;
                }
            }
        }
    }

    return dist[n];
    
}




signed main() {
    
    cin >> n >> m;
    while ( m -- ) {
        cin >> edge.from >> edge.to >> edge.score;
        graph[edge.from].push_back(edge.to);
        edges.push_back(edge);
    }

    

    int ans = bellman_ford();
    cout << ans << endl;
    



    return 0;
}
