#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18

const int nmax = (int ) 3e5 + 10;
int n, leaves;
vector<int > graph[nmax];
vector<int > clr, parent;
vector<int > subleafs;
vector<int > possmax;




void dfs(int u) {

    if (graph[u].size() == 0) {
        subleafs[u] = 1;
        possmax[u] = leaves;
        return ;
    }
    

    int mx = -inf;
    for (auto v : graph[u]) {
        dfs(v);        
        subleafs[u] += subleafs[v];         
        mx = max(possmax[v], mx);
    }

    if ( clr[u] == 1) {
        possmax[u] = mx;    
    } else { 
                
        int submx = -inf;
        for (auto v : graph[u]) {
            if (clr[v] == 1) {
                submx = max(submx, subleafs[v]);                
            }         
        }
        if ( submx != -inf) {
            possmax[u] = leaves - subleafs[u] + submx;
        } else {
            possmax[u] = leaves - subleafs[u] + 1;
        }
    }
}


signed main() {
    int n;
    cin >> n;
    clr.assign(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        cin >> clr[i];
    }

        parent.assign(n + 1, -1);
    for (int i = 2; i <= n; i ++) {
       cin >> parent[i];
       graph[parent[i]].push_back(i);    
    }


    for (int i = 1; i <= n; i ++) {
        leaves += ((int)graph[i].size() == 0);    
    }

    subleafs.assign(n + 1, 0);
    possmax.assign(n + 1, 0);
    dfs(1);
    cout << possmax[1] << endl;

    
    
    return 0;
}