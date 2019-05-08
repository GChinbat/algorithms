#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18

const int nmax = (int)1e6 + 10;

int n;
int a[nmax];

struct Node {
       
    int sum;
    int min_val;
    int max_val;
    int lo;
    int hi;

    Node * left;
    Node * right;
   
};


Node * build(Node * node, int lo, int hi) {
    
    node = (Node *)malloc(sizeof(Node));
    //node = new Node();
    node -> lo = lo;
    node -> hi = hi;

    if ( lo == hi) {
        node -> sum = a[lo];
        node -> min_val = a[lo];
        node -> max_val = a[lo];
        node -> left = NULL;
        node -> right = NULL;
        return node;
    }
    int mid = (lo + hi) / 2;
        
    node -> left = build(node -> left, lo, mid);
    node -> right = build(node -> right, mid + 1, hi);

    node -> sum = node -> left -> sum + node -> right -> sum;
    node -> min_val = min(node -> left -> min_val, node -> right -> min_val);
    node -> max_val = max(node -> left -> max_val, node -> right -> max_val);
    
    return node;
}


int get_sum(Node * node, int beg, int fin) {
    if ( node -> lo > fin || node -> hi < beg) return 0;
    if (beg <= node -> lo && node -> hi <= fin) return node -> sum;           
    return get_sum(node -> left, beg, fin) + get_sum(node -> right, beg, fin);
}  


int get_min(Node * node, int beg, int fin) {
    if (node -> lo > fin || node -> hi < beg) return inf;
    if (beg <= node -> lo && node -> hi <= fin) return node -> min_val;           
    return min(get_min(node -> left, beg, fin), get_min(node -> right, beg, fin));
}


int get_max(Node * node, int beg, int fin) {
    if (node -> lo > fin || node -> hi < beg) return -inf;
    if (beg <= node -> lo && node -> hi <= fin) return node -> max_val;
    return max(get_max(node -> left, beg, fin), get_max(node -> right, beg, fin));
}


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    Node * root;
    cout << "root : " << root << endl;
    root = build(root, 0, n - 1);

    int q;
    cin >> q;
    while ( q -- ) {
        int beg , fin;
        cin >> beg >> fin;
        cout << "sum : " << get_sum(root, beg, fin) << endl;
        cout << "min : " << get_min(root, beg, fin) << endl;
        cout << "max : " << get_max(root, beg, fin) << endl;
    }
   
    return 0;
}