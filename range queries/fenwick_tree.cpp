#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define mod 1000000007
#define inf (int)1e18

const int nmax = (int)1e5 + 10;
int n, a[nmax];
int tree[nmax];




int build(int beg, int fin) {

    int sum = a[fin];
    fin --;
    while (beg <= fin) {
        sum += tree[fin];
        fin -= fin & (-fin);
    }
    return sum;
}

int get_presum(int fin) {
    int sum = 0;
    while (fin > 0) {
        sum += tree[fin];
        fin -= (fin & - fin);
    }
    return sum;
}


int get_sum(int beg, int fin) {
    return get_presum(fin) - get_presum(beg - 1);
}

void add(int pos, int inc) {
    while (pos <= n) {
        tree[pos] += inc;
        pos += (pos & -pos);
    }
}


signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i  =0 ;i < n; i ++) {
        cin >> a[i + 1];
    }

    for (int i = 1; i <= n ;i ++) {
        tree[i] = build(i - (i&-i) + 1, i);
        cout << tree[i] << " ";
    }
    cout << endl;

    int q;
    cin >> q;
    while (q -- ) {
        int isadd, beg, fin;
        cin >> isadd >> beg >> fin;
        if(isadd) {
            add(beg, fin);
            for (int i  = 1; i <= n; i ++) {
                cout << tree[i] << " ";
            }
            cout << endl;
        } else {
            int res = get_sum(beg, fin);
            cout << res << endl;
        }
    
    }

    

    return 0;
}