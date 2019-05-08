#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007

const int nmax = (int)1e5 + 10;


int func(int x, int * a, int n) {
    
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        sum += abs(x - a[i]);   
    } 

    return sum;
}


int ternary_search(int n, int* a, bool isfirst) {
    
    int lo = 0;
    int hi = inf;

    while (lo + 1 < hi) {
        cout << lo << " " << hi << endl;
        int part = (hi - lo + 1) / 3;
        int mida = lo + part;
        int midb = hi - part;
        if ( func(mida, a, n) < func(midb, a, n)) {
            hi = midb;
        } else {
            lo = mida;   
        }
    }

    return lo;
}

signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int n;
    int a[nmax];

    freopen("in", "r", stdin);
    cin >> n;

    for (int i  =0; i < n; i ++) {
        cin >> a[i];
    }

    int ans = ternary_search(n, a);
    cout << ans << " :: ";
    cout << func(ans, a, n) << endl;
    


    return 0;
}