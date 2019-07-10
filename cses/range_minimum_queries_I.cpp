#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18 +10

const int nmax = (int)2e5 + 10;
int n, q;
int a[nmax];

int tree[nmax * 2 + 10];

void build(int id, int beg, int fin) {
    
    if (beg == fin) {
        tree[id] = a[beg];
        return ;
    }

    int mid = (beg + fin) / 2;

    build(id * 2, beg, mid);
    build(id * 2  + 1, mid + 1, fin);
    
    tree[id] = min(tree[id * 2], tree[id * 2 + 1]);

}

int query(int id, int beg, int fin, int qbeg, int qfin) {
    if ( qbeg <= beg && fin <= qfin) {
        return tree[id];
    }
    if ( fin < qbeg || qfin < beg ) {
        return inf;
    }
    
    int mid = (beg + fin) / 2;
    int resa = query(id * 2,     beg,     mid,  qbeg, qfin);
    int resb = query(id * 2 + 1, mid + 1, fin,  qbeg, qfin);
    
    return min(resa, resb);
}



signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    build(1, 0, n - 1);
             
    while ( q -- ) {
        int u, v;
        cin >> u >> v;
        u --; v -- ;
        cout << query(1, 0, n -1, u, v) << endl;
    }

    return 0;
}