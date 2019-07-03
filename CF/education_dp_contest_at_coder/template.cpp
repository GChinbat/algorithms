#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007


const int nmax = 22;
int n;
int rel[nmax][nmax];
int dp[(1 << 21)];


int solve(int womanmask) {
    
    int man_id = __builtin_popcount(womanmask);
    if (man_id == n) return 1;
    if (dp[womanmask] != -1) return dp[womanmask];

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        if (rel[man_id][i] == 1) {
            if ( (womanmask & (1 << i)) == 0) {
               ans += solve(womanmask | (1 << i));        
                ans %= mod;
            }
        }
    }
    return dp[womanmask] = ans;

}



signed main() {
     
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> rel[i][j];
        }
    }

    memset(dp, -1, sizeof dp);

    int res = solve(0);
    cout << res << endl;


    return 0;
}