#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007

const int nmax = (int)1e5 + 10;

signed main() {
        
    freopen("in", "r", stdin);

    int n, len;
    int a[nmax];

    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    cin >> len;

    deque<int > window;

    assert (len <= n);
    for (int i = 0; i < len; i ++) {
        
        while( window.size() && window.back() > a[i]) {
            window.pop_back();    
        }
        window.push_back(a[i]);
    }

    cout << endl;
    for (int i = 0; i < n; i ++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << -1 << " to  " << len - 1  << ": " << window.front() << endl;

    for (int i = len; i < n; i ++) {
        while( window.size() && window.back() > a[i]) {
            window.pop_back();    
        }
        window.push_back(a[i]);
        int beg = i - len;
        if (window.front() == a[beg]) {
            window.pop_front();
        }
        cout << beg << " to " << i << " : " << window.front() << endl;
    }
    

    return 0;
}