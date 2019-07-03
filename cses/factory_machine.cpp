#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+ 10

const int nmax = (int)2e5 + 10;
int n, t, k[nmax];


bool check(int limit) { 

    int sum = 0;
    for (int i = 0; i < n;  i ++) {
        sum += limit / k[i];
        if (sum >= t) return true;       
    }    
    if ( sum >= t) return true;
    return false;
    
}


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t;
    for (int i = 0; i < n; i ++) {
        cin >> k[i];
    }

    int lo = 0;
    int hi = inf;
    while ( lo < hi) {
        
        int mid = (lo + hi) / 2;
        bool ok = check(mid);
        if (ok) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << endl;

    return 0;
}