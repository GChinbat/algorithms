#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e6+7

const int nmax = (int)1e5 + 10;

int func(int x, int n, int * a) {  

        int sum = 0;
    for (int i = 0; i < n; i ++) {
            
        sum += (a[i] -  x)*(a[i] - x);
    }
    return sum;
    
}


int t_search(int n, int * a) {
    int lo = 0;
    int hi = inf;
    while(lo + 1 < hi) {
        int part = (hi - lo + 1)/ 3;
        int mida = lo + part;
        int midb = hi - part;
        if (func(mida, n, a) < func(midb, n, a)) {
            hi = midb;
        } else {
            lo = mida;
        } 
    }
    return lo;
}
    

signed main() {
    
    ios_base :: sync_with_stdio(false);

    freopen("in", "r", stdin);


    int n;
    int a[nmax];
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int ans = t_search(n, a);
    cout << ans << ": " << func(ans, n, a) << endl;
    

    return 0;
}