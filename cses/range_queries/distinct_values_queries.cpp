#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

const int nmax = (int)2e5 + 10;
int n, q, x[nmax];
set<int> tree[nmax * 4 + 10];


set<int > merger(set<int > a, set<int > b) {
    set<int > res;
    int alen = a.size();
    int blen = b.size();
    if (alen > blen) {
        res = a;    
        for (auto& v : b) {
            res.insert(v);
        }
    } else {
        res = b;
        for (auto& v : a) {
            res.insert(v);
        }
    }
    return res;
}


void build(int id, int beg, int fin) {
    if (beg == fin) {
        tree[id].insert(x[beg]);
        return ; 
    }
    int mid = (beg + fin) / 2;
    build(id * 2, beg, mid);
    build(id * 2 + 1, mid + 1, fin);
    tree[id] = merger(tree[id * 2], tree[id * 2 + 1]);
}

int qbeg, qfin;

set<int> query(int id, int beg, int fin) {
    set<int > res;
    if (qfin < beg || fin < qbeg) {
        return res;
    }
    if (qbeg <= beg && fin <= qfin) {
        return tree[id];
    }
    int mid = (beg + fin) / 2;
    set<int > a = query(id * 2, beg, mid);
    set<int > b = query(id * 2 + 1, mid + 1, fin);
    res = merger(a, b);
    return res;  
}



signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i ++) {
        cin >> x[i];
    }

    build(1, 0, n - 1);
    
    while (q -- ) {
        cin >> qbeg >> qfin;
        qbeg --;
        qfin --;
        cout << query(1, 0, n - 1).size() << endl;
    }



    return 0;
}