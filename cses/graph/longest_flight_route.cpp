#include <bits/stdc++.h>
using namespace std;   
#define pb push_back
#define nmax 100005
#define inf INT_MAX


vector<int > graph[nmax];


int n, m;
int dp[nmax];
int par[nmax];


int dfs(int u) {
    
    if (u == n) return dp[u] = 1;
             
    if(dp[u] != -1) return dp[u]; 

    int ans = -inf;
    for (auto v : graph[u]) {
       ans = max(ans, dfs(v) + 1);
    }
    if (ans == -inf + 1) {ans = -inf;}

    for (auto v : graph[u]) {
        if (ans == dp[v] + 1) {
            par[v] = u;
        }
    }
    
     
    return dp[u] = ans;
}


void gogo(int u) {
    cout << u << " ";
    for (auto v : graph[u]) {
        if (dp[v] + 1 == dp[u]) {
            gogo(v);
            break;
        }    
    }
}


signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    while ( m -- ) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
    }
    

    memset(dp, -1, sizeof dp);
    memset(par, -1, sizeof par);

    int res = dfs(1);
    if (res < -inf + n) {
        cout << "IMPOSSIBLE" << endl;
    } else {              
        cout << res << endl;
        gogo(1);
        cout << endl;
    }


    
    return 0;
}