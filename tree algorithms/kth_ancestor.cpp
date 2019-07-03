#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf(int)1e18+7
#define mod 1000000007

const int nmax = (int)2e5+10;
int n, in[nmax];
vector<int > tree[nmax];
int parent[26][nmax];


void build() { 
    
    for (int i = 1; (1 << i) <= n; i ++) {
        for (int u = 1; u <= n;  u ++) {
            parent[i][u] = parent[i - 1][parent[i - 1][u]];
        } 
    }

}


int get_kth_parent(int u, int k) {

    while(k > 0) {
        int i = 0;
        for (; (1 << i) <= k; ++ i) {}
        i --;
        u = parent[i][u];
        k -= (1 << i);
    }
    
    return u;
}


signed main() {
    
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    

    cin >> n;
    int m = n - 1;
    while (m --) {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        parent[0][v] = u;
        in[v] ++;
    }    
    build();

    int q;
    cin >> q;
    while (q --) {
        int u, k;
        cin >> u >> k;
        cout << get_kth_parent(u, k) << endl;
    }
    
    return 0;
}