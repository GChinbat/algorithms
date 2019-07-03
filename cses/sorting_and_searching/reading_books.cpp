#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7

const int nmax = (int)2e5 + 10;
int n, t[nmax];


signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i ++) {
        cin >> t[i];
    }
    
    sort(t, t + n);

    int aa = 0;
    int bb = 0;
    
    vector<int > vaa;
    vector<int > vbb;

    for (int i = n - 1; i >= 0; i -- ) {
        if (aa > bb) {
            bb += t[i]; 
            vbb.pb(t[i]);
        }
        else {
            aa += t[i];
            vaa.pb(t[i]);
        }
    }
    
    if (aa > bb) {
        swap(aa, bb);
        swap(vaa, vbb);
    }

    int dif = bb - aa;

    






    return 0;
}