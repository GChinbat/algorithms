#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define inf (int)1e18+7
#define mod 1000000007

struct union_find {
    
    vector<int >parent, mass;
    union_find(int n) {
        parent.assign(n + 1, 0);
        mass.assign(n + 1, 1);
        for (int i = 1; i <= n; i ++) {
            parent[i] = i;
        }
    }

    int get_parent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = get_parent(parent[x]);
    }

    bool is_same(int x, int y) {
        return get_parent(x) == get_parent(y);
    }

    void unite(int x, int y) {
        assert(is_same(x, y) == false);
        x = get_parent(x);
        y = get_parent(y);
        if (mass[x] > mass[y]) swap(x, y);
        assert(mass[x] <= mass[y]);
        parent[x] = y;
        mass[y] += mass[x];
    }
        
};


struct Edge {
    int u, v, w;
};

vector<Edge > edges;

bool comp(Edge a, Edge b) {
    return a.w < b.w;
}

int get_answer(int n) {
    
    union_find uf(n);
    
    int answer = 0;
    int edge_cnt = 0;
    for (auto edge : edges) {
        if (!uf.is_same(edge.u, edge.v)) {
            uf.unite(edge.u, edge.v);
            answer += edge.w;
            edge_cnt ++;
        }
        if (edge_cnt == n - 1) {
            break;
        }
    }

    return answer;
}


signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("in", "r", stdin);
    
    int n, m;
    cin >> n >> m;

    while( m -- ) {
        Edge edge;
        cin >> edge.u >> edge.v >> edge.w;
        edges.push_back(edge);
    }

    sort(edges.begin(), edges.end(), comp);

    int ans = get_answer(n);
        
    cout << ans << endl;

    return 0;
}