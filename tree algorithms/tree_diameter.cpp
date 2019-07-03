#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7

const int nmax = (int)2e5 + 10;
int n;
vector<int > tree[nmax];
int toleaf[nmax];
int diametr = 0;

void dfs(int u, int p) {
   
    int far = -1;
    int pre = -1;
    for (auto v : tree[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (toleaf[v] > far) {
            pre = far;
            far = toleaf[v];
        } else {
            pre = max(pre, toleaf[v]);
        }        
    }

    toleaf[u] = far + 1;
    diametr = max(diametr, far + pre + 2);
}





signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int m = n - 1;
    while ( m -- ) {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    dfs(1, 0);
   
    cout << diametr << endl;

    return 0;
}