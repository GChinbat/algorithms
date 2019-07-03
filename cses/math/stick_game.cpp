#include <bits/stdc++.h>
using namespace std;

#define nmax 1000005
int n, k, p[nmax];
int dp[nmax];
#define lose 1
#define win 0

string state = "WL";

signed main () {

    cin >> n >> k;
    for (int i = 0; i < k; i ++) {
        cin >> p[i];
    }    

    dp[ 0 ] = lose;
    for (int i = 1; i <= n; i ++) {
        dp[i] = lose;
        for (int j = 0; j < k; j ++) {
            if (i - p[j] < 0) continue;
            if (dp[i - p[j]] == lose) {
                dp[i] = win;
            }    
        } 
    }

    for (int i = 1; i <= n; i ++) {
        cout << state[dp[i]];
    }
    cout << endl;

    return 0;
}