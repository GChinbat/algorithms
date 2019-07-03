#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nmax 1000001

int notpr[nmax];
vector<int > pr;

void build() {
    
    for (int i = 2; i < nmax; i ++) {
        if (notpr[i]) continue;
        pr.pb(i);
        for (int j = i; j < nmax; j += i) {
            notpr[j] = true;
        }
    }

}

map<int, int > has;

void solve(int x) {
    
    for (auto p : pr) {
        if (p > x) break;
        while (x % p == 0) {
            has[p] ++;
            x /= p;
        }
    }
    
    if (x != 1) {
        has[x] ++;    
    }

}

int power_mod(int a, int b) {
    int c = 1;
    while (b) {
        if (b&1) c *= a;
        a *= a;
        b /= 2;
    }
    return c;
}


int calc(int p, int x) {
    // p ^ x - 1/ p - 1;
    int px = power_mod(p, x+ 1);
    px --;
    return px / (p - 1);

}



signed main() {
    
    int n;
    cin >> n;
    build();
    solve(n);


    int ans = 1;
    for (auto p : has) {
        cout << p.first << " " << p.second << endl;
        cout << calc(p.first, p.second) << endl;    
        ans *= calc(p.first, p.second);
    }
    cout << ans << endl;
       

    return 0;
}