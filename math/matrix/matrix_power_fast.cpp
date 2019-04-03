#include <bits/stdc++.h>
using namespace std;

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
                    c[i][j] += a[i][k] * b[k][j];
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
    
    mat c(2);
    c.create_identity();
    
    while(b) {
        if (b & 1) c.multiply(a.a);
        a.multiply(a.a);
        b /= 2;
    }
    return c;
}



signed main() {
    
    int b = 3;
    mat a(2);
    a.a[0][0] = 0;
    a.a[0][1] = 1;
    a.a[1][0] = 4;
    a.a[1][1] = 3;
    
    for (int i = 0; i < a.n; i ++) {
        for (int j = 0; j < a.n; j ++) {
            cout << a.a[i][j] << " ";
        } cout << endl;
    }
    
    mat res = power_mod(a, b);
    
    cout << endl;
    for (int i = 0; i < res.n; i ++) {
        for (int j = 0; j < res.n; j ++) {
            cout << res.a[i][j] << " ";
        } cout << endl;
    }
    return 0;
}