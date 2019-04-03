#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 

struct mat {
    int n;
    int ** a;
    mat (int n) {
        this -> n = n;
        allocate_memory(&a);
    }
    
    void allocate_memory(int *** c) {
        (*c) = (int **) malloc(sizeof (int *) * n);
        for (int i = 0; i < n; i ++) {
            *((*c) + i) = (int*) malloc(sizeof (int) * n);
        }
    }
    
    void create_identity() {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                a[i][j] = 0;
                if ( i == j ) a[i][j] = 1;
            }
        }
    }
    
    void multiply(int ** b) {
        int ** c;
        allocate_memory(&c);
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                c[i][j] = 0;
                for (int k = 0; k < n; k ++) {
                    c[i][j] += (a[i][k] * b[k][j]) % mod;
                    c[i][j] %= mod;
                }
            }
        }

        clear_memory(a);
        a = c;
    }
    
    void clear_memory(int ** c) {
        for (int i = 0; i < n; i ++) {
            free(c[i]);
        } free(c);
    }
};


mat power_mod(mat a, int b) {
    
    mat c(4);
    c.create_identity();
    
    while(b) {
        if (b & 1) c.multiply(a.a);
        a.multiply(a.a);
        b /= 2;
    }
    return c;
}


signed main() {
    
    mat a(4);
    
    for (int i = 0; i < a.n; i ++) {
        for ( int j = 0; j < a.n; j ++ ) {
            a.a[i][j] = 1;
            if (i == j ) a.a[i][j] = 0;
        }
    }
    
    int b;
    cin >> b;
    mat res = power_mod(a, b);
    cout << res.a[3][3] << endl;
    
    
    return 0;
}