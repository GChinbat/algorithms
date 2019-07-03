#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10


int n, m;
struct UF{
    vector<int > parent, rank;
    
    void init(int n) {
        parent.assign(n + 1, 0);
        rank.assign(n + 1, 0);
        for (int i = 1; i <= n; i ++) {
            parent[i] = i;
        }
    }

    int seek(int x) {
        if (x == parent[x]) return x;
        return parent[x] = seek(parent[x]);
    }

    void unify(int x, int y) {
        x = seek(x);
        y = seek(y);
        if (x == y) return ;

        if (rank[x] > rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            if (rank[x] == rank[y]) {
                rank[y] ++;
            }
        }
    }

};


signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    UF uf;

    cin >> n >> m;
    
    uf.init(n);
    
    while ( m -- ) {
        int u, v;
        cin >> u >> v;
        uf.unify(u, v);
    }

    set<int > roots;
    for (int i = 1; i <= n; i ++) {
        roots.insert(uf.seek(i));
    }

    cout << roots.size() - 1 << endl;
    auto u = *roots.begin();
    
    for (auto v : roots) {
        if ( u == v) continue;
        cout << u << " " << v << endl;
    }
    
    

    return 0;
}