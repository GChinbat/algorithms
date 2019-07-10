#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define nmax 200005
 
 
int n;
int succ[nmax];
 
int go_one(int u) {
    return succ[u];
} 
 
int go_two(int u) {
    return succ[succ[u]];
}
 
int dp[nmax];
 
void fun(int beg) {
    
    if (dp[beg] != -1) return ;
 
    int turtoise = go_one(beg);
    int rabbit = go_two(beg);
                    
    while (turtoise != rabbit) {
        if (dp[rabbit] != -1) return ;
        if (dp[turtoise] != -1) return ;
        turtoise = go_one(turtoise);
        rabbit = go_two(rabbit);
    }
 
    int a = beg;
    int b = rabbit;
 
    while (a != b) {
        a = go_one(a);
        b = go_one(b);
    }
    
    int first = a;
    int cnt = 1;
    a = go_one(a);
    while (first != a) {
        a = go_one(a);
        cnt ++;
    }
    dp[first] = cnt;
    a = go_one(first);
    while (first != a) {
        dp[a] = cnt;
        a = go_one(a);    
    }
 
}
 
int dfs(int u) {
 
    if (dp[u] != -1) return dp[u];
   
    int v = go_one(u);
    dp[u] = dfs(v) + 1;
    return dp[u];
}
 
 
signed main() {
    
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> succ[i];
    }
    
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i ++) {
        fun(i);
    }
    
    for (int i = 1; i <= n; i ++) {
        int ans = dfs(i);
        cout << ans << " ";
    }
 
    return 0;
}