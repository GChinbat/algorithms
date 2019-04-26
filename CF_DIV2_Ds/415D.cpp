#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007 
#define int long long

int dp[2002][2002];

vector<int > divs[2002];

void build() {
    
    for (int i = 1; i <= 2000; i ++ ) {
        for (int j = 1; j <= i; j ++) {
            if ( i % j == 0) {
                divs[i].push_back(j);
            }
        }
    }
    
}

signed main() {
    int n, k;
    cin >> n >> k;
    
    build();
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i ++) {
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= k; i ++) {
        for (int j = 1; j <= n; j ++) {
            for (auto id : divs[j]) {
                dp[i][j] += dp[i - 1][id];
                dp[i][j] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i<= n; i ++) {
        ans += dp[k][i];
        ans %= mod;
    }
    cout << ans << endl;
    
    
    
    return 0;
}