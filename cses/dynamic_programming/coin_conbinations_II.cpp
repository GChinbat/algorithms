#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int n, c[110];
int dp[101][1000001];


signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> n >> x;
    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
    }

    sort(c + 1, c + n + 1);

    memset(dp, 0, sizeof dp);

    
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= x; j ++) {
            if (j - c[i] >= 0) {
                dp[i][j] += dp[i][j - c[i]];
                dp[i][j] %= mod;
            }
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
            
        }
    }

    cout << dp[n][x] << endl;
    
    return 0;
}