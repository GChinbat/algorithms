#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7


int n, q;
string grid[1010];
int dp[1010][1010];

int begx, begy, finx, finy;

int get_sum() {
    
    int res = dp[finx][finy] + dp[begx][begy] - dp[begx][finy] - dp[finx][begy];
    return res;
}



signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i ++) {
        cin >> grid[i];
        for (int j = 0 ; j< n; j ++) {
            dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
            if (grid[i][j] == '*') dp[i + 1][j + 1] ++;
        }
    }

  
    while ( q -- ) {
        cin >> begx >> begy >> finx >> finy;
        begx --;
        begy --;
        cout << get_sum() << endl;
    }

    return 0;
}