#include <bits/stdc++.h>
using namespace std;


struct Matrix {
    int ** a;
    int n, m;
    Matrix(int n, int m) {
        this -> n = n;
        this -> m = m;
        a = allocate_memory(a, n, m);
        assert(a != NULL);
    }
    
    void transpose() {
        int ** b;
        b = allocate_memory(b, m, n);
        assert(b != NULL);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                b[j][i] = a[i][j];
            }
        }
        
        free_memory(a);        
        a = b;
        swap(n, m);
    }
   
    int ** allocate_memory(int ** c, int _n, int _m) {
        
        c = (int **) malloc(sizeof (int *) * _n);
        for (int i = 0; i < _n; i ++) {
            c[i] = (int *) malloc(sizeof (int) * _m);
        }
        
        return c;
    }
    
    void free_memory(int ** c) {
        for (int i = 0; i < n; i ++) {
            free(c[i]);
        } free(c);
    }
   
/*   
    ~Matrix() {
        cout << "freeing ... ";
        for (int i = 0; i < n; i ++) {
            free(*(a + i));
        } free(a);
    }*/
};


signed main() {
    
    Matrix mat(5, 3);
    int cnt = 0;
    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 3; j ++) {
            mat.a[i][j] = ++cnt;
            cout << mat.a[i][j] << " "; 
        } cout << endl;
    }
    
    mat.transpose();
    
    cout << endl;
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 5; j ++) {
            cout << mat.a[i][j] << " ";
        } cout << endl;
    }
    cout << "ending" << endl;
    
    return 0;
}