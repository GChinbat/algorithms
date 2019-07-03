#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18 + 10;
#define base 1000000001

const int nmax = (int)2e5+10;
int n, x;
int a[nmax];

signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> x;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i] += base;
    }

    

    return 0;
}