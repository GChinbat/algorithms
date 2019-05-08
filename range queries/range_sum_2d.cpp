#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007

const int nmax = 505;

int presum[nmax][nmax];

void build(int n, int m, int a[505][505]) {
    
    memset(presum, 0, sizeof presum);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            presum[i][j] = a[i][j] + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
        }
    }

}

int get_sum(int begx, int begy, int finx, int finy) {
    int res = presum[finx][finy] - presum[finx][begy - 1] - presum[begx - 1][finy] + presum[begx - 1][begy - 1];
    return res;
}


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    //freopen("in", "r", stdin);

    int n, m;
    int a[nmax][nmax];

    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m ; j ++) {
            cin >> a[i][j];
        }    
    }

    build(n, m, a);
    
    for (int i = 0 ; i <= n; i ++) {
        for (int j = 0; j <= m; j ++) {
            cout << presum[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int q;
    cin >> q;
    while(q --) {
        int begx, begy;
        int finx, finy;
        cin >> begx >> begy >> finx >> finy;
        assert(begx > 0 && begx <= n);
        assert(begy > 0 && begy <= m);
        assert(finx > 0 && finx <= n);
        assert(finy > 0 && finy <= m);
                 
        cout << get_sum (begx, begy, finx, finy) << endl;
    }



    return 0;
}