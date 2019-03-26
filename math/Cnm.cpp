#include <bits/stdc++.h>
using namespace std;
#define int long long


int gcd(int x, int y) {
    while(y != 0) {
        int tmp_x = x;
        x = y;
        y = tmp_x % y;
    }
    return x;
}

/*
    extended gcd::
    gcd (a, b) = s * a + t * b
    X = a, Y = b 
*/

/*
    x = c * X + d * Y
    y = e * X + f * Y
      
    x % y = z => x = q*y + z
    z = x - q*y

    z = c * X + d * Y - q * (e * X + f * Y)
    z = c * X + d * Y - q * e * X - q * f * Y
    z = (c - q * e) * X + (d - q * f) * Y
   
*/

/* 
    s = c, t = d
*/

pair<int, int > extended_gcd(int x, int y) {
    int c = 1, d = 0;  // X
    int e = 0, f = 1;  // Y   
    while( y != 0 ) {
        int tmp_x = x, tmp_c = c, tmp_d = d;
        x = y; c = e; d = f;
        int q = tmp_x / y;
        y = tmp_x % y;
        e = tmp_c - q * e;
        f = tmp_d - q * f;
    }
    return make_pair(c, d);
}

/*
    (1/x) % mod = ???
    
    gcd(x, mod) = 1
    s*x + t*mod = 1 % mod
    s * x  + t * 0 = 1 % mod
    s * x = 1 % mod
    
    s => 1/x 
    
    extended_gcd(x, mod)
    
*/


int get_inverse_mod(int x, int mod) {
    assert (gcd(x, mod) == 1);
    pair<int, int > res = extended_gcd(x, mod);
    while (res.first < 0) {
        res.first += mod;
        res.first %= mod;
    }
    assert(res.first >= 0);
    return res.first;
}


/*
    n! / ((n -m)!*m !)
*/

int Cmn(int n, int m, int mod) {
    
    int above = 1;
    int below_n_minus_m = 1;
    int below_m = 1;
    
    for (int i = 1; i <= n; i ++) {
        
        above = (above * i) % mod;
        
        if ( i <= n - m ) {
            below_n_minus_m = (below_n_minus_m * get_inverse_mod(i, mod)) % mod;
        }   
        
        if ( i <= m ) {
            below_m = ((below_m % mod) * (get_inverse_mod(i, mod)%mod)) % mod;
        }
    }

    int result = ((above * below_n_minus_m) % mod * below_m) % mod; 
    return result;
}


signed main() {
   
    int x, y;
    cin >> x >> y;
    cout << "gcd :: ";
    cout << gcd(x, y) << endl;
        
    cout << "extended_gcd ";
    pair<int, int > ans = extended_gcd(x, y);
    cout << ans.first << " " << ans.second << endl;
   
    cout << "Cmn ::" ;    
    cout << Cmn(x, y, 10000007) << endl;
   
    return 0;
}
