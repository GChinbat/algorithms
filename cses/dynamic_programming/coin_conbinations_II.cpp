#include <bits/stdc++.h>
using namespace std;

int n, c[110];
int dp[101][1000001];

int solve(int id, int rem) {
    
    if (rem < 0) return 0;

    if (id == n) {
        return rem == 0;   
    }


    int &ans = dp[id][rem];
    if (ans != -1) return ans;
    ans = 0;
    ans += solve(id, rem - c[id]);
    ans += solve(id + 1, rem);


    return ans;
}


signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> n >> x;
    for (int i = 0; i < n; i ++) {
        cin >> c[i];
    }

    sort(c, c + n);

    memset(dp, -1, sizeof dp);

    int res = solve(0, x);

    cout << res << endl;


    return 0;
}