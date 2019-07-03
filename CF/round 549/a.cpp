#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7

const int nmax = (int) 1e6 + 10;
int n, a[nmax];
int le = 0, ri = 0;

signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        le += 1 - a[i];
        ri += a[i];
    }
    
    for (int i = 0; i < n; i ++) {
        le -= (1 - a[i]);
        ri -= a[i];
        if (le == 0 || ri == 0) {
            cout << i + 1 << endl;
            break;
        }
    }
    
    
    return 0;
}