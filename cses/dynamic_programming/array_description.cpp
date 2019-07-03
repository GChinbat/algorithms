#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18
#define mod 1000000007


const int nmax = (int)1e5 + 10;
int n, m;
int x[nmax];


int dp[nmax][110];



signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> x[i];
    }
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n;  i ++) {
        
        if (i == 1) {
            if (x[i] == 0) {
                for (int j = 1; j <= m; j ++) {
                    dp[i][j] = 1;
                }    
            } else {
                dp[i][x[i]] = 1;
            }
            continue;
        }
    
        if (x[i] == 0) {
            for (int j = 1; j <= m; j ++) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;  
            }
        } else {
            dp[i][x[i]] = (dp[i - 1][x[i]] + dp[i - 1][x[i] - 1] + dp[i - 1][x[i] + 1]) % mod;  
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= m; i ++) {
        ans += dp[n][i];   
        ans %= mod;
    }
    cout << ans << endl;
   

    return 0;
}