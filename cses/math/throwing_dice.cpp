#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007


struct Mat{
    int n, m;
    vector<vector<int > > x;
    Mat(int n, int m) {
        this->n = n;
        this->m = m;
        x.assign(n, vector<int > (m, 0));
    }
    void Identity() {
        assert(n == m);
        for (int i = 0; i < n; i ++) {
            x[i][i] = 1;
        }
    }    
};


Mat multi(Mat a, Mat b) {

    Mat c(a.n, b.m);

    assert(a.m == b.n);

    for (int i = 0; i < a.n; i ++) {
        for (int j = 0; j < b.m; j ++) {
            for (int k = 0; k < a.m; k ++) {
                c.x[i][j] += (a.x[i][k] * b.x[k][j]) % mod;
                c.x[i][j] %= mod;
            }
        }
    }

    return c;
}


Mat power_mod(Mat a, int b) {
    Mat c(a.n, a.m);
    c.Identity();

    while (b) {
        if (b & 1) {
            c = multi(c, a);
        }
        a = multi(a, a);
        b /= 2;
    }
    
    return c;
}


signed main() {
    
    int tar;
    cin >> tar;
    int n = 6; 
    Mat a(n, n);
    for (int i = 0; i < n - 1; i ++) {
        a.x[i][i + 1] = 1;
        a.x[n - 1][i] = 1;
    } a.x[n - 1][n - 1] = 1;

    a = power_mod(a, tar);
    
    Mat t(n, 1);
    vector<int > tmp = {1, 1, 2, 4, 8, 16};
    
    for (int i = 0; i < n; i ++) {
        t.x[i][0] = tmp[i];
    }

    t = multi(a, t);
  
    cout << t.x[0][0] << endl;


    return 0;
}