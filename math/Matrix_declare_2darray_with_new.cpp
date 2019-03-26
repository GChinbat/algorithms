#include <bits/stdc++.h>
using namespace std;

class Mat {
    public :
        int **a;
        int *n, *m;
        
        Mat (int n, int m) {
            this -> n = new int;
            this -> m = new int;
            *(this -> n) = n;
            *(this -> m) = m;
            a = new int*[n];
            for (int i = 0; i < n; i ++) {
                a[i] = new int[m];
            }
        }
        
        ~Mat() {
            for (int i = 0; i < *n; i ++) {
                delete [] a[i];
            } delete [] a;
            delete n;
            delete m;
        }
};


signed main() {
    
    Mat * mat = new Mat(10, 2);
    
    int cnt = 0;
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 2; j++) {
            mat -> a[i][j] = ++cnt;
            cout << mat -> a[i][j] << " ";
        } cout << endl;
    }
    
    delete mat;
    
    cout << "after delete :: " << endl;
    cout << mat -> n << endl;
    cout << mat -> m << endl;
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 2; j ++) {
            cout << mat -> a[i][j] << " ";
        } cout << endl;
    }
    
    return 0;
}
