#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007

const int nmax = (int)2e5 + 10;

int n, q;

int a[nmax];
int lazy[nmax * 4 + 10];
int tree[nmax * 4 + 10];

void build(int id, int beg, int fin) {
    if (beg == fin) {
        tree[id] = a[beg];
        return ;
    }
    int mid = (beg + fin) / 2;
    build(id * 2, beg, mid);
    build(id * 2  +1, mid + 1, fin);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}


int qbeg, qfin, val;

void propogate(int id, int beg, int fin) {

    tree[id] += (fin - beg + 1) * lazy[id];    

    if (beg != fin) {
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
    }
        
    lazy[id] = 0;

}


void update(int id, int beg, int fin) {
    
    if ( fin < qbeg || qfin < beg) return ;
    
    propogate(id, beg, fin);         
    
    if ( qbeg <= beg && fin <= qfin) {
        lazy[id] += val;
        return ;
    }

    int mid = (beg + fin) / 2;
    update(id * 2, beg, mid);
    update(id * 2 + 1, mid + 1, fin);

}

int qpos;

int query(int id, int beg, int fin) {
    
    if (qpos < beg || qpos > fin) return 0;
    propogate(id, beg, fin);
        
    if (beg == fin && qpos == beg) {
        return tree[id];
    }

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
        if (dir == 2) {
            cin >> qpos;
            qpos --;
            cout << query(1, 0, n - 1) << endl; 
        } else {
            cin >> qbeg >> qfin >> val;
            qbeg --; qfin --;
            update(1, 0, n - 1);
        }
    }

   
    return 0;
}