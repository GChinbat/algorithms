#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7


const int nmax = (int)2e5 + 10;
int n, x;
int prefix[nmax];
unordered_map<int, int > sums;

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    sums[0] = 1;
    for (int i = 1; i <= n; i ++) {
        int aa;
        cin >> aa;
        prefix[i] = prefix[ i - 1] + aa;
        sums[prefix[i]] ++;
    }
    
    int ans = 0;
    for (int i = n;  i > 0; i --) {
        int target = prefix[i] - x;
        sums[prefix[i]] --;
        ans += sums[target];    
    }

    cout << ans << endl;

    return 0;
}