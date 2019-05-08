#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define inf (int)1e18+10
#define mod 1000000007
#define pb push_back

const int nmax = (int)1e5 + 10;


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    freopen("in", "r", stdin);

    int n;
    int a[nmax];
    int targetsum;

    cin >> n;
    for (int i = 0; i  < n; i ++) {
        cin >> a[i];
    }

    cin >> targetsum;
    sort(a, a + n);

    for (int i = 0; i < n; i ++) {
        cout << a[i] << " ";
    }
    cout << endl;

    int beg = 0;
    int fin = n - 1;
    int tmpsum = a[beg] + a[fin];
    bool ok = false;


    while ( beg < fin ) {
        cout << beg << " " << fin << " " << a[beg] << " " << a[fin] << " " << tmpsum << endl;
        if ( tmpsum == targetsum ) {
            ok = true;
            cout << "yes " << beg << " " << fin << endl;
            break;
        }
        if (tmpsum > targetsum) {
            tmpsum -= a[fin];
            tmpsum += a[--fin];
        } else  {
            tmpsum -= a[beg];
            tmpsum += a[++beg];
        }      
    }

    if (!ok) {
        cout << "no " << endl;
    }
    
    return 0;
}