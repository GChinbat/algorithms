#include <bits/stdc++.h>
using namespace std;

#define nmax 200005

int n, q;
int succ[nmax];    
int dp[30][nmax];


void build() {
    
    for (int i = 1; i <= n; i ++) {
        dp[0][i] = succ[i];
    }

    for (int i = 1; i < 30; i ++) {
        for (int j = 1; j <= n; j ++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    
}

int query(int beg, int k) {

    while ( k > 0) {
        int i = 0;
        for (; (1 << i) <= k; i ++) {}
        i --;

        beg = dp[i][beg];
        k -= (1 << i);   
    }    
    return beg;
}


signed main() {

    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> succ[i];
    }

    build();
    
    while ( q -- ) {
        int beg, k;
        cin >> beg >> k;
        int res = query(beg, k);
        cout << res << endl;
    }
    
    


    return 0;
}