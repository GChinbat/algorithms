#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define inf (int)1e18+10
#define mp make_pair

#define beg second
#define fin first

const int nmax = (int)2e5 + 10;
pair<int, int > movies[nmax];

signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        cin >> movies[i].beg >> movies[i].fin;
    }

    sort(movies, movies + n);
    
    int last_fin = 0;
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        if ( movies[i].beg >= last_fin) {
            ans ++;
            last_fin = movies[i].fin;
        }
    }

    cout << ans << endl;



    return 0;
}