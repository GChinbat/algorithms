#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7
#define mod 1000000007

struct union_find { 

    vector<int > parent, mass;    

    union_find(int n) {
        parent.assign(n + 1, 0);
        mass.assign(n + 1, 1);
        for (int i  = 1; i <= n; i ++) {
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
        if (mass[x] < mass[y]) swap(x, y);
        assert(mass[x] >= mass[y]);
        parent[y] = x;
        mass[x] += mass[y];
    }
    
};

    
signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    freopen("in", "r", stdin);

    int n;
    cin >> n;

    union_find uf(n);

    int m;
    cin >> m;
    
    while( m -- ) {
        int u, v;
        cin >> u >> v;
        if (!uf.is_same(u, v)) {
            uf.unite(u, v);
        }
    }

    set<int > roots;
    for (int i = 1; i <= n; i ++) {
        roots.insert(uf.get_parent(i));
    }
    
    for(auto root: roots) {
        cout << root << " :: " << uf.mass[root] << endl;
    }
    

    return 0;
}