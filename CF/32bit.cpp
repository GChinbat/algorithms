#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int nmax = (int) 1e6 + 10;

int power(int a, int b) {
    int c = 1;
    while(b) {
        if ( b & 1) c *= a;
        a *= a;
        b /= 2;
    }
    return c;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    
    int n = 32;
    cout << INT_MAX << endl;
    
    int sum = 0;
    for (int i = 0; i < 32; i ++) {
        sum += power(2, i);
    }
    
    cout << sum << endl;
    cout << (int)power(2, 32) - 1LL << endl;
    
    return 0;
}