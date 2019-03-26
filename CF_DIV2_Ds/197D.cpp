#include <bits/stdc++.h>
using namespace std;
#define int long long

const int nmax = (int) (1 << 18);
int a[nmax];


struct Node {
    int val;
    bool isor;
    Node * left;
    Node * right;
};


void do_operand(Node * node) {
    int result;
    if ( node -> isor) {
       result = (node -> left -> val) | (node -> right -> val);
    } else {
       result = (node -> left -> val) ^ (node -> right -> val); 
    }
    node -> val = result;
}


Node * build_tree(int lo, int hi) {
    Node * node = (Node *) malloc(sizeof(Node));
    if (lo == hi) {
        node -> val = a[lo];
        node -> isor = false;
        node -> left = NULL;
        node -> right = NULL;
    } else {
        int mid = (lo + hi) / 2;
        node -> left = build_tree(lo, mid);
        node -> right = build_tree(mid + 1, hi);
        node -> isor = false;
        if ( node -> left -> isor) {}
        else node -> isor = true;
        
        do_operand(node);
    }
    return node;
}


int update_idx, update_val;


void update_value(int lo, int hi, Node * node) {
    if ( lo <= update_idx && update_idx <= hi) {
        if ( lo == hi) {
            node -> val = update_val;
        } else {
            int mid = (lo + hi) / 2;
            update_value(lo, mid, node -> left);
            update_value(mid + 1, hi, node -> right);
            do_operand(node);
        }
    } 
}


signed main() {
   
    int n, m;
    cin >> n >> m;
    int nn = (1 << n);
    for (int i = 0; i < nn; i ++) {
        cin >> a[i];
    }

    Node * root = build_tree(0, nn - 1);

    while (m --) {
        cin >> update_idx >> update_val;
        update_idx --;
        update_value(0, nn - 1, root);
        cout << root -> val << endl;
    }

    return 0;
}