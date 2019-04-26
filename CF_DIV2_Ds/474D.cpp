#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 

const int nmax = (int) 1e5 + 10;
int dp[nmax], presum[nmax];

void build(int k) {
    
    for (int i = 1; i < k; i ++) {
        dp[i] = 1;
    } dp[k] = 2;
    
    for (int i = k + 1; i < nmax; i ++) {
        dp[i] = dp[i - 1] + dp[i - k];
        dp[i] %= mod;
    }
    presum [0] = 0;
    for (int i = 1; i < nmax; i ++) {
        presum[i] = presum[i - 1] + dp[i];
        presum[i] %= mod;
    }
}

int query(int beg, int fin) {
    int res = presum[fin] - presum[beg - 1];
    while ( res < 0) {
        res += mod;
    }
    return res % mod;
}

signed main() {
    int t, k;
    cin >> t >> k;
    
    build(k);
    while( t -- ) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << endl;
    }
    

    return 0;
}