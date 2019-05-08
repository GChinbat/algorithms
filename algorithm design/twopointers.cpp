#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007

const int nmax = (int)1e5 + 10;
int n, a[nmax];
int targetsum;
                         

signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    freopen("in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> targetsum;

    int p1 = 0;
    int p2 = 0;
    
    int tmpsum = a[p1];

    
    bool ok = false;

    while (p1 < n) {
        
        while ( p2 + 1 < n && tmpsum + a[p2 + 1] <= targetsum) {
            tmpsum += a[++ p2];
        }
        if ( tmpsum == targetsum) {
            ok = true;
            cout << "yes " << p1 << " " << p2 << endl;    
            break;
        }
    
        tmpsum -= a[p1 ++]; 
    }

    if (!ok) {
        cout << "no " << endl;
    }
  
    return 0;
}