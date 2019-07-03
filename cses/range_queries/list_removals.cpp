#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18
#define nmax (int)2e5+10

int n;
int x[nmax];
int tree[nmax * 4];
int lazy[nmax * 4];


void build(int id, int beg, int fin) {
    if (beg == fin) {
        tree[id] = beg;
        return ;
    }
    int mid = (beg + fin) / 2;
    build(id * 2, beg, mid);
    build(id * 2 + 1, mid + 1, fin);
}


void propagate(int id, int beg, int fin) {
    if (beg != fin) {
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id]; 
        lazy[id] = 0;
    }
}

int qbeg, qfin, val;


void update(int id, int beg, int fin) {
    
    propagate(id, beg, fin);

    if (qfin < beg || fin < qbeg) {
        return ;
    }
    
    if (qbeg <= beg && fin <= qfin) {
        lazy[id] += val;
        propagate(id, beg, fin);
        return ;
    }

    int mid = (beg + fin) / 2;
    update(id * 2, beg, mid);
    update(id * 2 + 1, mid + 1, fin); 
    
}

int qpos;

int query(int id, int beg, int fin) {
    
    propagate(id, beg, fin);

    if (qpos < beg || fin < qpos) {
        return 0;
    }
    
    if (beg == fin && fin == qpos) {
        return tree[id] + lazy[id];
    }

    int mid = (beg + fin) / 2;
    int resa = query(id * 2, beg, mid);
    int resb = query(id * 2 + 1, mid + 1, fin);
    return resa + resb;
}


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> x[i];
    }

    build(1, 0, n - 1);
    
    int m = n;
    while ( m -- ) {
        cin >> qpos;
        qpos --;
        int rpos = query(1, 0, n - 1);
        cout << x[rpos] << endl;
        qbeg = qpos;
        qfin = n - 1;
        val = 1;
        update(1, 0, n - 1);
        
    }



    return 0;
}