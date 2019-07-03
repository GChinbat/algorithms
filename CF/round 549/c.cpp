#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7

const int nmax = (int) 1e6 + 10;


vector<int > tree[nmax];
bool c[nmax];
int parent[nmax];
int n, root;

set<int > ans;

void dfs(int u) {
    
    int cnt = c[u];
    for (auto v : tree[u]) {    
        cnt += c[v];
        dfs(v);
    }
    
    if (cnt - 1 == tree[u].size()) {
        if (u != root) {
            ans.insert(u);
        }
        
    }
    
}

signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
     
    cin >> n;
    
    root = -1;
    for (int u = 1; u <= n; u ++) {
        int p;
        cin >> p >> c[u];
        parent[u] = p;
        if ( p == -1 ) root = u;
        else {
            tree[p].push_back(u);
        }
    }
    
    dfs(root);
        
    if ( ans.size() == 0) ans.insert(-1);    
    for (auto x : ans) {
        cout << x << " ";
    } cout << endl;
    
    
    return 0;
}