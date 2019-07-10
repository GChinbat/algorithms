#include <bits/stdc++.h>
using namespace std;
#define nmax 200005
#define pb push_back


vector<int > graph[nmax];

int dp[nmax];

void dfs(int u) {
    dp[u] = 1;
    for (auto v : graph[u]) {
        dfs(v);
        dp[u] += dp[v];
    }
}



signed main() {
    

    int n;
    cin >> n;

    for (int i = 2; i <= n; i ++) {
        int p; 
        cin >> p;
        graph[p].pb(i);    
    }

    dfs(1);

    for (int i = 1; i <= n; i ++) {
        cout << dp[i] - 1 << " ";
    }
    cout << endl;
    
    return 0;
}