#include <bits/stdc++.h>
using namespace std;


struct Matrix {
    int ** a;
    int n, m;
    Matrix(int n, int m) {
        this -> n = n;
        this -> m = m;
        a = allocate_memory(n, m);
        assert(a != NULL);
    }
    
    void transpose() {
        int ** b;
        b = allocate_memory(m, n);
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
    
    int ** allocate_memory(int _n, int _m) {
        
        int ** c = (int **) malloc(sizeof (int *) * _n);
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
    
    
    void add(int ** b, int _n, int _m) {
        assert(n == _n);
        assert(m == _m);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                a[i][j] += b[i][j];
            }
        }
    }
    
    void multiply_by_value(int val) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                a[i][j] *= val;
            }
        }
    }
    
    void multiply_by_matrix(int ** b, int _n, int _m) {
        assert(m == _n);
        int ** c = allocate_memory(n, _m);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < _m; j ++) {
                c[i][j] = 0;
                for (int k = 0; k < _n; k ++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        free_memory(a);
        a = c;
        m = _m;
    }
    
    void print() {
        for (int i = 0; i <n; i ++) {
            for (int j = 0;j  < m; j ++) {
                cout << a[i][j] << " ";
            } cout << endl;
        }
    }    
};


signed main() {
    
    Matrix mat(5, 3);
    int cnt = 0;
    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 3; j ++) {
            mat.a[i][j] = ++ cnt;
        }
    }
    
    mat.print();
    mat.transpose();
    
    cout << "transpose :: " << endl;
    mat.print();
    cout << "multiply value :: " << endl;
    mat.multiply_by_value(5);
    mat.print();
    cout << "add value :: " << endl;
    Matrix tmp(3, 5);
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 5; j ++) {
            tmp.a[i][j] = 1;
        }
    }
    mat.add(tmp.a, tmp.n, tmp.m);
    mat.print();
    
    cout << "multiply by matrix :: " << endl;
    
    mat.print();
    cout << " X " << endl;
    tmp.transpose();
    tmp.print();
    cout << " == " << endl;
    
    mat.multiply_by_matrix(tmp.a, tmp.n, tmp.m);
    mat.print();
    
    cout << "create Identity matrix :: " << endl;
    Matrix iden(3, 3);
    for (int i = 0; i < iden.n; i ++) {
        for (int j = 0; j < iden.m; j ++) {
            iden.a[i][j] = int(i == j);
        }
    }
    iden.print();
    
    cout << "create multiply identity matrix ::" << endl;
    
    cout << "matrix * identity = " << endl;
    mat.multiply_by_matrix(iden.a, iden.n, iden.m);
    mat.print();
    
    
    cout << "identity * matrix = " << endl;
    iden.multiply_by_matrix(mat.a, mat.n, mat.m);
    iden.print();
    
    
    return 0;
}