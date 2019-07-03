#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf (int)1e18+7
#define pb push_back

const int nmax = (int)2e5 + 10;

int n, m;

int x[nmax];


struct Node {
    int far_max;
    vector<int > elements;
    int last_max;    
} tree[nmax * 4];



Node merging(Node a, Node b) {
    
    Node res;
    res.far_max = max(a.far_max, b.far_max);
    res.elements = a.elements;
    

    int pre = a.last_max;
    for (int i = 0; i < b.elements.size(); i ++) {
       res.elements.pb(b.elements[i]);
       pre = max(b.elements[i], pre + b.elements[i]);
       res.far_max = max(res.far_max, pre);                     
    }

    res.last_max = pre;
    return res;
}


void build(int id, int beg, int fin) {
    if (beg == fin) {
        tree[id].far_max = x[beg];
        tree[id].elements.pb(x[beg]);
        tree[id].last_max = x[beg];
        return ;
    }
    int mid = (beg + fin) / 2;
    build(id * 2, beg, mid);
    build(id * 2 + 1, mid + 1, fin);
    
    tree[id] = merging(tree[id * 2], tree[id * 2 + 1]);

}

int qbeg, qfin;

Node query(int id, int beg, int fin) {
    
    if (qfin < beg || fin < qbeg) {
        Node node;
        node.far_max = -inf;
        node.last_max = -inf;
        return node;
    }

    if (qbeg <= beg && fin <= qfin) {
        return tree[id];
    }

    int mid = (beg + fin) / 2;

    Node a = query(id * 2, beg, mid);
    Node b = query(id * 2 + 1, mid + 1, fin);
    
    return merging(a, b);
}

int qpos, qval;

void update(int id, int beg, int fin) {
    if (qpos < beg || qpos > fin) return ;
    if (beg == fin && qpos == fin) {
        tree[id].far_max = qval;
        tree[id].last_max = qval;
        tree[id].elements[0] = qval;  
        return ;
    }
    int mid = (beg + fin ) / 2;
    update(id * 2, beg, mid);
    update(id * 2 + 1, mid + 1, fin);

    tree[id] = merging(tree[id * 2], tree[id * 2 + 1]);
}




signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; i ++) {
        cin >> x[i];
    }

    build (1, 0, n - 1);

    qbeg = 0;
    qfin = n - 1;


    while ( m -- ) {
        cin >> qpos >> qval;
        qpos -- ;
        update(1, 0, n - 1);
        cout << query(1, 0, n - 1).far_max << endl;
    }



    return 0;
}