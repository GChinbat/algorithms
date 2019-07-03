#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10
#define mod 1000000007


const int nmax = (int)1e6+10;

int n;
int dp[nmax];


signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    
    dp[0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= 6; j ++) {
            if ( i - j < 0) continue;
            dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }

    cout << dp[n] << endl;
    

    return 0;
}