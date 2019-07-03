#include <bits/stdc++.h>
using namespace std;
#define d int
#define rep(i, a, b) for (d i = a; i<=b; i ++)

d dp[5001][5001];
    
d main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    d n = a.size();
    d m = b.size();
    
    rep(i, 1, n) dp[i][0] = i;
    
    rep(i, 1, m) dp[0][i] = i;
    
    rep(i, 0, n-1)
        rep(j, 0, m-1) 
            dp[i + 1][j + 1] = min(dp[i][j + 1] + 1, min(dp[i + 1][j] + 1, dp[i][j] + (a[i] != b[j])));
        
    cout << dp[n][m];                      

    return 0;
}