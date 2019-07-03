#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[(int)3e5 + 10];

signed main() {
    
    cin >> n;
    
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    
    int ans = a[0] / 3;
    int rem = a[0] % 3;
    for (int i = 1; i < n; i ++) {
        int tot = a[i] / 2;
        int mn = min(tot, rem);
        ans += mn;
        tot -= mn;
        rem -= mn;
        int arem = tot * 2 + a[i] % 2;
        ans += arem / 3;
        rem += arem % 3;
    }
    
    cout << ans << endl;
    
    return 0;
}