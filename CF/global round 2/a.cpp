#include <bits/stdc++.h>
using namespace std;

int n;
int a[300003];

signed main() {
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
        
    int beg = 0;
    int fin = n - 1;
    int ans = 0;
    if ( a[beg] != a[fin]) {
        ans = (fin - beg);
    } else {
        for (int i = beg; i < fin; i ++) {
            if ( a[i] != a[beg]) {
                ans = fin - i;
                break;
            }
        }
        for (int i = fin; i > beg; i --) {
            if ( a[i] != a[fin]) {
                ans = max(i - beg, ans);
            } 
        }
    }
    cout << ans << endl;

    return 0;
}