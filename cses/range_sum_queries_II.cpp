#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf int (int)1e18 + 10


const int nmax = (int)2e5 + 10;
int n, q;
int a[nmax];
int tree[nmax * 4 + 10];


void build(int id, int beg, int fin) {
    
    if (beg == fin) {
        tree[id] = a[beg];
        return ;        
    }

    int mid = (beg + fin) / 2;
    build(id * 2, beg, mid );
    build(id * 2 + 1, mid + 1, fin);
    tree[id] = tree[id * 2]  + tree[id * 2 + 1];

}

int pos, val;

void update(int id, int beg, int fin) {
    
    if ( beg == fin && beg == pos) {
        tree[id] = val;
        return ;
    }
    if (pos < beg || fin < pos) {
        return ;
    }
    int mid = (beg + fin) / 2;
    update(id * 2, beg, mid);
    update(id * 2 + 1, mid + 1, fin);
    tree[id] = tree[id * 2]  + tree[id * 2 + 1];
    
}

int qbeg, qfin;

int query(int id, int beg, int fin) {
    if (qfin < beg || fin < qbeg) return 0;
    if (qbeg <= beg && fin <= qfin) return tree[id];
    int mid = (beg + fin) / 2;
    
    int resa = query(id * 2, beg, mid);
    int resb = query(id * 2 + 1, mid + 1, fin);

    return resa + resb;
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
        int dir;
        cin >> dir;
        if (dir == 1) {
            cin >> pos >> val;
            pos --;
            update(1, 0, n -1);
        } else {
            cin >> qbeg >> qfin;
            qbeg --; qfin --;
            int res = query(1, 0, n - 1);
            cout << res << endl;
        }
    }

    return 0;
}