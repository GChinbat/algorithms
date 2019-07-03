#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10

const int nmax = (int)2e5 + 10;

int n, q;   
int prefix[nmax];


int get_sum(int beg, int fin) {
    return prefix[fin] - prefix[beg - 1];
}

signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    
    for (int i = 1; i <= n; i ++) {
        int a;
        cin >> a;
        prefix[i] = prefix[i - 1] + a;
    }

    while ( q -- ) {
        int beg, fin;
        cin >> beg >> fin;
        cout << get_sum(beg, fin) << endl;
    }
    

    return 0;
}