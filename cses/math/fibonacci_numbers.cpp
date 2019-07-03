#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10
#define mod 1000000007


struct mat {
    int a[2][2] = {{0, 0},{0, 0}};
    void identity() {
        for (int i = 0; i < 2; i ++) {
            a[i][i] = 1;
        }   
    }
};

mat multiply(mat A, mat B) {
    
    mat C;
    for (int i = 0; i < 2; i ++) {
        for (int j = 0 ;j < 2; j ++) {
            C.a[i][j] = 0;
            for (int k = 0; k < 2; k ++) {
                C.a[i][j] += (A.a[i][k] * B.a[k][j]) % mod;
                C.a[i][j] %= mod;          
            }
        }
    }
    return C;

}


mat power_mod(mat A, int b) {

    mat C;
    C.identity();
    while ( b ) {
       if ( b & 1 ) C = multiply(C, A);
       A = multiply(A, A);
       b /= 2;
    }
    
    return C;
}


signed main() {

    ios_base:: sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    mat A;
    A.a[0][0] = 0; A.a[0][1] = 1;
    A.a[1][0] = 1; A.a[1][1] = 1;
    
   // mat B = multiply(A, A);
    
    mat B = power_mod(A, n);    
    
    cout << B.a[0][1] << endl;

   

    return 0;
}