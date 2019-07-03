#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int n, m;
bool dir[22][22];
int dp[21][(int)1<<21];

int solve(int last, int bitmask) {

    int cnt = __builtin_popcount(bitmask);
    if (cnt == n) {
        return 1;
    }

    int& ans = dp[last][bitmask];
    if (ans != -1) return ans;

    ans = 0;
    for (int i = 0; i < n; i ++) {
        if (i == n - 1) {
            if (cnt != n - 1) {
                continue;
            }
        }
        if (dir[last][i]) {
            if ((bitmask & ( 1 << i)) == 0) {
                ans += solve(i, (bitmask | ( 1 << i)));
                ans %= mod;    
            } 
        }
    }
    
    return ans;  
}


signed main() {
    
    cin >> n >> m;
    while (m -- ) {
        int u, v;
        cin >> u >> v;
        u --;
        v --;
        dir[u][v] = true;
    }

   
    memset(dp, -1, sizeof dp);

    int ans = solve(0, 1);

    cout << ans << endl;

    return 0;
}