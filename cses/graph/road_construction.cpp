#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long 
#define inf (int)1e17+ 10

int n, m;

struct UF {
    vector<int > parent, sized;
    int mx_size = 1;
    int comp;
    void init(int n) {
        parent.assign(n + 1, 0);
        sized.assign(n + 1, 1);
        for (int i = 1; i <= n; i ++) {
            parent[i] = i;
        }
        comp = n;
    }

    int seek(int x) {
        if(parent[x] == x) return x;
        return parent[x] = seek(parent[x]);
    }

    void unify(int x, int y) {
        x = seek(x);
        y = seek(y);
        if ( x == y) return;
        comp --;
        if (sized[x] > sized[y]) {
            parent[y] = x;
            sized[x] += sized[y];
            mx_size = max(mx_size, sized[x]);
        } else {
            parent[x] = y;
            sized[y] += sized[x];
            mx_size = max(mx_size, sized[y]);
        }
    }

};


signed main() {


    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    UF uf;
    uf.init(n);
    while ( m -- ) {
        int u, v;
        cin >> u >> v;
        uf.unify(u, v);
        cout << uf.comp << " "  << uf.mx_size << endl;
    }


    return 0;
}