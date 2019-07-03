#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7

int dp[505][505];    

int cutter(int a, int b) {

    if (a == b) return 0;    

    int& ans = dp[a][b];
    if (ans != -1) return ans;

    ans = inf;
    for (int i = 1; i < a; i ++) {
        ans = min(ans, cutter(i, b) + cutter(a - i, b) + 1);
    }

    for (int i = 1; i < b; i ++) {
        ans = min(ans, cutter(a, i) + cutter(a, b - i) + 1);
    }
    
    return ans;
}


signed main() {

    int a, b;
    cin >> a >> b;


    memset(dp, -1, sizeof dp);

    int ans = cutter(a, b);        

    cout << ans << endl;



    return 0;
}