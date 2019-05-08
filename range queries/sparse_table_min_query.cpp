#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7
#define mp make_pair
#define pb push_back
#define mod 1000000007

const int nmax= (int)1e5 + 10;

int dp[25][nmax];

void build(int n, int * a ) {

    for(int i = 0; i < n; i ++) {
        dp[1][i] = a[i];
    }
    for (int len = 2; len <= n; len *= 2) {
        for (int i = 0 ; i < n - len + 1; i ++) {
            int beg = i;
            int prelen = len / 2;
            dp[len][beg] = min(dp[prelen][beg], dp[prelen][beg + prelen]);
        }
    }     
}

int get_min(int beg, int fin) {

    int len = fin - beg + 1;
    int tarlen = 1;
    while(true) {
        if (tarlen * 2 > len) {
            break;
        }
        tarlen *= 2;    
    }    

    return min(dp[tarlen][beg], dp[tarlen][fin - tarlen + 1]);
}


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int n;
    int a[nmax];
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    build(n, a);
    
    for (int len = 1; len <= n; len *= 2) {
        for (int i = 0; i < n - len + 1; i ++) {
            cout << dp[len][i] << " ";
        } cout << endl;    
    }
    cout << endl;

    int q;
    cin >> q;
    while ( q -- ) {
        int beg, fin;
        cin >> beg >> fin;

        cout << get_min(beg, fin) << endl;

    }




    return 0;
}