#include <bits/stdc++.h>
using namespace std;

class Mat {
    int **a;
    int *n, *m;
    
    public :
            
        Mat (int n, int m) {
            this -> n = (int*) malloc(sizeof(int));
            this -> m = (int*) malloc(sizeof(int));
            *(this -> n) = n;
            *(this -> m) = m;
            a = (int**) malloc(sizeof(int*) * n);
            for (int i = 0; i < n; i ++) {
                a[i] = (int*) malloc(sizeof(int) * m);
            }
        }
        
        ~Mat() {
            for (int i = 0; i < *n; i ++) {
                free (a[i]);
            } free(a);
            free(n);
            free(m);
        }
        
        int get_row_number() {
            return *n;
        }
        
        int get_col_number() {
            return *m;
        }
        
        int get_val_of_a(int i, int j) {
            assert(i < *n);
            assert(j < *m);
            return *(*(a + i) + j);
        }
        
        void set_val_of_a(int i, int j, int val) {
            assert(i < *n);
            assert(j < *m);
            *(*(a + i) + j) = val;
        }
};


void test_for_3d_array() {
    
    int *** d;
    int n = 2, m = 3, k = 4;
    
    d = (int ***) malloc(sizeof (int**) * n);
    for (int i = 0; i < n; i ++) {
        *(d + i) = (int **) malloc(sizeof (int **) * m);
    }
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            *(*(d + i) + j) = (int *) malloc(sizeof (int) * k);
        }
    }
    
    for (int i = 0; i < n; i ++) {
        cout << i << " :: " << endl;
        for (int j = 0; j < m; j ++) {
            for (int h = 0; h < k; h ++) {
                cout << d[i][j][h] << " ";
            } cout << endl;
        }
    }
    
}


void test_for_declare_multi_dimensional_pointer() {
    int *******************************************************************************************************************************************************ff;
    // no error when compiled
}

signed main() {
    
    test_for_3d_array();
    test_for_declare_multi_dimensional_pointer();
    
    
    Mat * mat = new Mat(10, 4);
    
    cout << mat -> get_row_number() << endl;
    cout << mat -> get_col_number() << endl;
    int cnt = 0;
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 4; j++) {
            mat -> set_val_of_a(i, j, ++cnt);
            cout << mat -> get_val_of_a(i, j) << " ";
        } cout << endl;
    }
    
    delete mat;
    
    cout << "after delete :: " << endl;
    cout << mat -> get_col_number() << endl;
    cout << mat -> get_row_number() << endl;
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 4; j ++) {
            cout << mat -> get_val_of_a(i, j) << " ";
        } cout << endl;
    }
    
    return 0;
}
