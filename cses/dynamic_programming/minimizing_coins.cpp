#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10


const int nmax = (int)1e6 + 10;
int n, x;
int c[110];
int dp[nmax];


signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; i ++) {
        cin >> c[i];
    }

    for (int i = 0; i <= x; i ++) {
        dp[i] = inf;
    }
    dp[0] = 0;
    for (int i = 1; i <= x; i ++) {
        for (int j = 0; j < n; j ++) {
            if ( i - c[j] < 0) continue;
            dp[i] = min(dp[i - c[j]] + 1, dp[i]);
        }
    }

    if (dp[x] == inf) {
        dp[x] = -1;
    }
    cout << dp[x] << endl;




    return 0;
}