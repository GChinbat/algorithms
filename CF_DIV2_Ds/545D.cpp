#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int > t;

signed main() {
    
    cin >> n;
    t.assign(n, 0);
    for (int i  =0; i < n; i ++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    
    int waiting = 0;
    int ans = 0;
    for (auto s : t) {
        if ( waiting <= s) {
            ans ++;
            waiting += s;
        }
    }
    cout << ans << endl;

    return 0;
}