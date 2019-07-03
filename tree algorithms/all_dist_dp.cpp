#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007
 
#define node first
#define deep second
#define fi 0
#define se 1
 
const int nmax = (int)2e5 + 10;
int n;
vector<int > tree[nmax];
    
 
pair<int, int > toleaf[2][nmax];
 
void dfs1(int u, int p) {
 
    toleaf[fi][u] = mp(0, 0);
    toleaf[se][u] = mp(0, 0);
 
    
    for (auto v : tree[u]) {
        if ( v == p ) continue;
        dfs1(v, u);
        if (toleaf[fi][u].deep < toleaf[fi][v].deep + 1) {
            toleaf[se][u] = toleaf[fi][u];
            toleaf[fi][u].deep = toleaf[fi][v].deep + 1;
            toleaf[fi][u].node = v;
        } else {
            if(toleaf[se][u].deep < toleaf[fi][v].deep + 1) {
                toleaf[se][u].deep = toleaf[fi][v].deep + 1;
                toleaf[se][u].node = v;
            }
        }
    }   
 
}
 
pair<int, int > mxpath[nmax];
 
 
void dfs2(int u, int p) {
    
     if (p != 0) {
        
        pair<int, int > ans = {0, 0};
        
        if (toleaf[fi][p].node == u) {
            ans.deep = toleaf[se][p].deep + 1;
            ans.node = p;   
        } else {
            ans.deep = toleaf[fi][p].deep + 1;
            ans.node = p;
        } 
        
        if (mxpath[p].node != u) {
            if (mxpath[p].deep + 1 > ans.deep) {
                ans.deep = mxpath[p].deep + 1;
                ans.node = p;
            }
        }
 
        mxpath[u] = ans;
     }   
    
    for (auto v : tree[u]) {
        if (v == p) continue;
        dfs2(v, u);
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
 
    dfs2(1, 0);
 
    for (int i = 1; i <= n; i ++) {
        cout << max(mxpath[i].deep, toleaf[fi][i].deep) << " ";
    }
    cout << endl;
    
    return 0;
}