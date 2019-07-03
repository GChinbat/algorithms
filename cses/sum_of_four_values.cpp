#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10


const int nmax = (int)2e5+10;

int n, x, a[nmax];

map<int, pair<int, int > > has;
map<int, bool > exist;



signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >>n >> x;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            int tmp = a[i] + a[j];
            has[tmp] = mp(i, j);                            
            exist[tmp] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            int target = x - (a[i] + a[j]);
            if ( exist[target] ) {
                pair<int, int > tmp = has[target];
                if (i != tmp.first && j != tmp.first && i != tmp.second && j != tmp.second) {
                    cout << i + 1 << " " << j + 1 << " " << tmp.first + 1 << " " << tmp.second + 1 << endl;
                    return 0;
                }    
            }
        }
    }

    puts("IMPOSSIBLE");
                       

    return 0;
}