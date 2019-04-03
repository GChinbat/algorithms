#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007


struct mat {
    int n, m;
    vector<vector<int > > a;
    mat(int n) : n(n), m(n) {
        a.assign(n, vector<int > (n, 0));
    }
    
    mat(int n, int m) : n(n), m(m) {
        a.assign(n, vector<int > (m, 0));
    }
    
    void make_identity() {
        for (int i = 0; i < n; i ++) {
            a[i][i] = 1;
        }
    }
    
    void multiply(mat b) {
        vector<vector<int > > c;
        c.assign(n, vector<int > (b.m, 0));
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < b.m; j ++) {
                for (int k = 0; k < m; k ++) {
                    c[i][j] += (a[i][k] * b.a[k][j]) % mod;
                    c[i][j] %= mod;
                }
            }
        }
        
        a = c;
        n = a.size();
        m = a.back().size();
    }
};


mat powermod(mat a, int b) {
    
    mat c(a.n);
    c.make_identity();
    while(b) {
        if (b & 1) c.multiply(a);
        a.multiply(a);
        b /= 2;
    }
    
    return c;
}


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    mat a(m);
    for (int i = 0; i < m - 1; i ++) {
        a.a[i][i + 1] = 1;
    }
    a.a[m - 1][0] = 1;
    a.a[m - 1][m - 1] = 1;
    
    mat res = powermod(a, n - 1);
    
    mat f(m, 1);
    
    for (int i = 0; i < m; i ++) {
        f.a[i][0] = 1;
    } f.a[m - 1][0] = 2;
    
    res.multiply(f);
    
    cout << res.a[0][0] << endl;
    
    return 0;
}