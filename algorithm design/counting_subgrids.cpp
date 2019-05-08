#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define int long long
#define inf (int)1e18+7
#define mod 1000000007



int n, m;
string grid[22];


int solve() {
    
    int ans = 0;
    for (int rowa = 0; rowa < n; rowa ++) {
        for (int rowb = rowa + 1; rowb < n; rowb ++) {
            int cnt = 0;
            for (int col = 0; col < m; col ++) {
                if (grid[rowa][col] == 'b' && grid[rowb][col] == 'b') {
                    cnt ++;
                }
            }
            ans += ((cnt * (cnt - 1)) / 2);
        }
    }

    return ans;
}

int solve1() {
    
    bitset<22> tmp[22];
    for (int i = 0; i <n; i ++) {
        tmp[i] = bitset<22> (grid[i], 0, m, 'w', 'b');
        cout << tmp[i] << endl;
    }

    int ans = 0;
    for (int rowa = 0; rowa < n; rowa ++) {
        for (int rowb = rowa + 1; rowb < n ;rowb ++) {
            int cnt = (tmp[rowa] & tmp[rowb]).count();
            ans += ((cnt * (cnt - 1)) / 2);
        }
    }
    
    return ans;
}



signed main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    cin >> n >> m;
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i ++) {
            cin >> grid[i];
            cout << grid[i] << endl;
    }

    int res = solve();
    cout << res << endl;

    int res1 = solve1();
    cout << res1 << endl;
    
    return 0;
}