#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007


const int nmax = (int)1e5 + 10;

int presum[nmax];


void build(int n, int * a) {

    presum[0] = 0;
    for (int i = 1; i <= n; i ++) {
        presum[i] = presum[i - 1] + a[i - 1];
    }

    for (int i = 0; i <= n; i ++) {
        cout << presum[i] << ", ";
    }
    cout << endl;
    
}

int get_sum(int beg, int fin) {
    return presum[fin] - presum[beg - 1];
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
                        
    int q;
    cin >> q;

    while ( q -- ) {
        int beg, fin;
        cin >> beg >> fin;
        assert(beg != 0);
        assert(fin != 0);
        cout << get_sum(beg, fin) << endl;
    }



    
    return 0;
}