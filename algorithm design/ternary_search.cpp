#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define mod 1000000007
#define inf (int)1e18+7



const int nmax = (int)1e5 + 10;


int ternary_search(int lo, int hi, int* a) {

    while ( lo + 1 < hi) {
        
        int di = (hi - lo + 1) / 3;
        int mida = lo + di;
        int midb = hi - di;
        if ( a[mida] < a[midb]) {
            hi = midb;        
        }
        else {
            lo = mida;    
        }
    }

    int ans = min(a[lo], a[hi]);
    cout << ans << endl;
    
    return ans; 
}

int bin_search(int lo, int hi, int* a) {
    
    int n = hi + 1;
    a[n] = inf;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        
        int t = 0;
        while (mid + t < n && a[mid] == a[mid + t]) {
            t ++;    
        }
        if ( a[mid] < a[mid + t] ) {
            hi = mid;
        } 
        if(a[mid] > a[mid + t]) {
            lo = mid + t;
        }
    }

    int ans = min(a[lo], a[hi]);
    cout << ans << endl;
    
    return ans;
}




signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);    
    
    freopen("in", "r", stdin);

    int n, a[nmax];
    
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    ternary_search(0, n - 1, a);
    bin_search(0, n - 1, a);

        
    return 0;
}