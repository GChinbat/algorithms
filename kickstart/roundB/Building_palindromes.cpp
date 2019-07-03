#include <bits/stdc++.h>
using namespace std;

int prefix[26][100010];

bool ask(int beg, int fin) {
    
    beg --;
    
    int even = 0;
    int odd = 0;
    for (int i  =0 ; i < 26; i ++) {
        int dif = prefix[i][fin] - prefix[i][beg];
        if (dif & 1) odd ++;
        else even ++;
    }
    
    int dif = fin - beg;
    if (dif & 1)  {
        if (odd == 1) return true;
        else return false;
    } else {
        if (odd == 0) return true;
        else return false;
    }
    
}

signed main() {
    
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int test, testno = 0;
    cin >> test;
    while(test -- ) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        
        memset(prefix, 0, sizeof prefix);
        
        for (int i = 0; i < 26; i ++) {
            for (int j = 1; j <= n; j ++) {
                if ((int)s[j - 1] == (int) ('A' + i)) {
                    prefix[i][j] = prefix[i][j - 1] + 1;
                } else {
                    prefix[i][j] = prefix[i][j - 1];
                }
            }
        }

        int ans = 0;
        while(q -- )
        {
            int beg, fin;
            cin >> beg >> fin;
            ans += ask(beg, fin);
            
        } 
        cout << "Case #" << ++testno << ": " << ans << endl;
    }

    return 0;
}