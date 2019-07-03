#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007


const int nmax = (int)1e6 + 10;
int n, x, c[nmax];
int dp[nmax];


signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; i ++) {
        cin >> c[i];
    }

    dp[0] = 1;

    for (int i = 1; i <= x; i ++) {
        for (int j = 0; j < n; j ++) {
            if ( i - c[j] < 0) continue;
            dp[i] += dp[i - c[j]];
            dp[i] %= mod;
        }
    }


    cout << dp[x] << endl;



    return 0;
}