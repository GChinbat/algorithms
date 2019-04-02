#include <bits/stdc++.h>
using namespace std;

struct mat {
    int n, m;
    int ** a;
    mat (int n, int m) {
        this -> n = n;
        this -> m = m;
    }
    
    
    
};


int power_mod(int a, int b, int mod) {
    int c = 1;
    while(b) {
        if (b & 1) c *= a, c %= mod;
        a *= a;
        a %= mod;
        b /= 2;
    }
    return c;
}



signed main() {
    
    int mod = 10000000007;
    int a, b;
    while(true) {
        cin >> a >> b;
        cout << power_mod(a, b, mod) << endl;
    }
    
    return 0;
}