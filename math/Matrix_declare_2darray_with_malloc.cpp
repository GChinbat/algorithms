#include <bits/stdc++.h>
using namespace std;

class Mat {
    public :
        int **a;
        int *n, *m;
        
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
};


signed main() {
    
    Mat * mat = new Mat(10, 4);
    
    cout << *mat -> n << endl;
    cout << *mat -> m << endl;
    int cnt = 0;
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 4; j++) {
            mat -> a[i][j] = ++cnt;
            cout << mat -> a[i][j] << " ";
        } cout << endl;
    }
    
    delete mat;
    
    cout << "after delete :: " << endl;
    cout << mat -> n << endl;
    cout << mat -> m << endl;
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 4; j ++) {
            cout << mat -> a[i][j] << " ";
        } cout << endl;
    }
    
    return 0;
}
