#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007


const int nmax = (int)1e5 + 10;
int a[nmax];
int ans[nmax];


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    freopen("in", "r", stdin);


    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    stack <int > pre;
    

    for (int i = 0; i < n; i ++) {
        while (pre.size() && pre.top() >= a[i]) {
            pre.pop();
        }
        if ( pre.size() == 0) {
            ans[i] = -1;
        } else {
            ans[i] = pre.top();
        }
        pre.push(a[i]);
    } 

    cout << endl;
    for (int i = 0; i < n; i ++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i ++) {
        cout << ans[i] << " "; 
    }
    cout << endl;


    return 0;
}