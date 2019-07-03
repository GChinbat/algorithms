#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10
#define mod 1000000007

int n;
string grid[1100];
int dp[1100][1100];



signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i ++) {
        cin >> grid[i];
    }

    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            
            if (grid[i][j] == '*') continue;
            if (i == j && i == 0) {
                dp[i][j] = 1;
            } else {
                if (j - 1 >= 0) {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= mod;
                } 
               
                if (i - 1 >= 0) {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= mod;
                }   
            }
        }
    }

    cout <<  dp[n - 1][n - 1] << endl;


    return 0;
}