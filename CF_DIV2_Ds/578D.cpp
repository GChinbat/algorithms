#include <bits/stdc++.h>
using namespace std;
#define int long long

const int nmax = (int ) 2e5 + 10;
int a[nmax], prefix[nmax], suffix[nmax];


signed main() {
    
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int mult = 1;
    while( k -- ) {
        mult *= x;
    }
    
    prefix[0] = 0;
    for (int i = 1; i <= n; i ++) {
        prefix[i] = prefix[i - 1] | a[i];
    }
    suffix[n + 1] = 0;
    for (int i = n; i >= 1; i --) {
        suffix[i] = suffix[i + 1] | a[i];
    }
    
    int ans = -1;
    for (int i = 1; i <= n; i ++) {
        int val = prefix[i - 1] | (a[i] * mult) | suffix[i + 1];
        ans = max(ans, val); 
        
    }
    cout << ans << endl;
    return 0;
}