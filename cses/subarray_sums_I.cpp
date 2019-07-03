#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10

const int nmax = (int)2e5+10;
int n, x;
int a[nmax];


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> x;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    
    queue<int > q;
    int qsum = 0;
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        q.push(a[i]);
        qsum += a[i];
        while(qsum > x) {
            int val = q.front(); q.pop();
            qsum -= val;    
        }
        if (qsum == x) {
            ans ++;
        }                                     
    }

    cout << ans << endl;
                        
    return 0;
}