#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7


int a[5005];
int dp[2][5005][5005];



int solve(int isfirst, int first, int last) {

    if (first > last) {
        return 0;    
    }
    
    int &res = dp[isfirst][first][last];

    if (res != -1) return res;

    if (isfirst) {
        res = solve(isfirst ^ 1, first + 1, last) + a[first];
        res = max(res, solve(isfirst ^ 1, first, last - 1) + a[last]);
    }
    else {
        res = solve(isfirst ^ 1, first + 1, last);
        res = min(res, solve(isfirst ^ 1, first, last - 1));
    }

    return res;
}


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;

    for (int i = 0 ;i < n; i ++) {
        cin >> a[i];
    }



    memset(dp, -1, sizeof dp);
    int ans = solve(1, 0, n - 1);
    cout << ans << endl;


    return 0;
}