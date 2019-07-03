#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+19

const int nmax = (int)5000 + 10; 
int n, x;
pair<int, int > a[nmax];
                                         

signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; i ++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i ++) {
        
        int lo = i + 1;
        int hi = n - 1;

        int target = x - a[i].first;
        while (lo < hi) {
            int tmp = a[lo].first + a[hi].first;
            if (tmp == target) {
                cout << a[i].second << " " << a[lo].second << " " << a[hi].second << endl;
                return 0;
            }

            if (tmp > target) {
                hi --;
            }
            else {
                lo ++;
            }
        }
    }

    puts("IMPOSSIBLE");

    

    
    return 0;
}