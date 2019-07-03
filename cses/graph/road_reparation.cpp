#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10

int n, m;

struct Edge {
    int u, v, w;
    bool operator<(const Edge B) const{
        return w < B.w;
    }
}edge;


vector<Edge > edges;

struct UF {
    vector<int > parent, rank;
    void init(int n) {
        parent.assign(n + 1, 0);
        rank.assign(n + 1, 0);
        for (int i = 1; i <= n; i ++) {
            parent[i] = i;
        }
    }

    int seek(int x) {
        if (parent[x] == x) return x;
        return parent[x] = seek(parent[x]);
    }

    void unify(int x, int y) {
        x = seek(x);
        y = seek(y);
        if (x == y) return ;

        if ( rank[x] > rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            if (rank[x] == rank[y]) {
                rank[y] ++;
            }
        }
    }
};

int solve() {

    UF uf;
    uf.init(n);
    int sum = 0;
    int edge_cnt = 0;
    for (auto e : edges) {
        int x = uf.seek(e.u);
        int y = uf.seek(e.v);
        if (x == y) continue;
        uf.unify(x, y);
        sum += e.w;
        edge_cnt ++;               
    }    
    if (edge_cnt != n - 1) {
        return -1;
    }
    return sum;
}


signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    while ( m--) {
        cin >> edge.u >> edge.v >> edge.w;
        edges.pb(edge);
    }

    sort(edges.begin(), edges.end());
      
    int ans = solve();
    if (ans == -1) {
        puts("IMPOSSIBLE");
    }
    else cout << ans << endl;

    return 0;
}