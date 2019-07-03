#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 2000000014

int n;
int dp[501][501 * 251];

int solve(int id, int rem) {
    if (rem < 0) return 0;
    if (id > n) {
        return (rem == 0);
    }    
    int& ans = dp[id][rem];

    if (ans != -1) return ans;

    ans = 0;
    ans += solve(id + 1, rem - id);
    ans %= mod;
    ans += solve(id + 1, rem);
    ans %= mod;
    return ans;
}


signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        sum += i;
    }
    if (sum & 1) {
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;

    memset(dp, -1, sizeof dp);
    int res = solve(1, sum);

    cout <<(res / 2) % 1000000007  << endl;



    return 0;
}