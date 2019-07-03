#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
const int nmax = (int) 1e6 + 10;

inline int up(char ch){ return 'z' - ch; }
inline int lo(char ch){ return ch - 'a'; }
inline int eq(char ch){ return 1; }
int dp[2002][2002];
int tmp[2002];


signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    //freopen("out", "w", stdout);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    memset(dp, 0, sizeof dp);
    

    dp[n][0] = 1;
    
    for (int i = n - 1; i >= 0; i --) {
        for (int j = 0; j <= k; j ++) {
            
            if (j - (n - i) >= 0) dp[i][j] = (up(s[i]) * dp[i + 1][j - (n - i)]) % mod;
            dp[i][j] += (lo(s[i]) * dp[i + 1][j]) % mod;
            dp[i][j] %= mod;
            // eq
           // cout << i << ", " << j << " ===> ";
            int last = i;
            for (int t = i + 1; t < n; t ++) {

               // cout << j - (n - t) * ( t - i + 1) << ", ";

                if (j - (n - t) * (t - i + 1) >= 0) {
                    dp[i][j] += (up(s[t]) * dp[t + 1][j - (n - t) * (t - i + 1)]) % mod;
                    dp[i][j] %= mod;
                    last = t;
                } else {
                   break;
                }
            }
            for (int t = n - 1; t > last; t --) {
                if (j - (n - t) * (t - i + 1) >= 0) {
                    dp[i][j] += (up(s[t]) * dp[t + 1][j - (n - t) * (t - i + 1)]) % mod;
                    dp[i][j] %= mod;
                } else {
                   break;
                }
            }

            dp[i][j] += tmp[j];
            dp[i][j] %= mod;

            // es
            if (j == 0) {
                dp[i][j] ++;
                dp[i][j] %= mod;
            }

            tmp[j] = tmp[j] + (lo(s[i]) * dp[i + 1][j]) % mod;
            tmp[j] %= mod;
       }
    }
    
    
    cout << dp[0][k] << endl;
    
    return 0;
}