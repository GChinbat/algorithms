#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007

const int nmax = (int)1e5 + 10;
int n, x[110];

int dp[110][nmax];          



signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);


    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> x[i];
        sum += x[i];
    }


    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= sum; j ++) {
            dp[i][j] |= dp[i - 1][j];
            if (j - x[i] < 0) continue;
            dp[i][j] |= dp[i - 1][j - x[i]];
        }
    }

    vector<int > ans;
    for (int i = 1; i <= sum; i ++) {
        if (dp[n][i]) ans.pb(i);    
    }
    cout << ans.size() << endl;
    
    for (auto a : ans) {
        cout << a << " "; 
    }
    cout << endl;

    

    




    


    return 0;
}