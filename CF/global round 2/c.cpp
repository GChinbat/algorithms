#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int a[555][555], b[555][555], c[555][555];
signed main() {
    
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> b[i][j];
        }
    }
    
    for (int i = 0; i < n; i ++) {
        for (int j =0; j < m; j ++) {
            if ( a[i][j] == b[i][j]) {
                c[i][j] = 0;
            } else {
                c[i][j] = 1;
            }
        }
    }
    
    bool ok = true;
    for (int i = 0; i < n; i ++) {
        int row = 0;
        for (int j = 0; j < m; j ++) {
            row += c[i][j]; 
        }
        if ( row & 1) ok = false;
    }
    for (int j = 0; j < m; j ++) {
        int col = 0;
        for (int i = 0; i < n; i ++) {
            col += c[i][j];
        }
        if( col & 1 ) ok = false;
    }
    if ( ok) puts("Yes");
    else puts("No");

    return 0;
}