#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7
#define base 257
#define mod 1000000007
#define nmax 1000010


string s;
int n;

int p[nmax];

int keys1[nmax];
int keys2[nmax];

void build() {
    
    p[0] = 1;
    for (int i = 1; i <= n; i ++) {
        p[i] = (p[i - 1] * base) % mod;
        p[i] %= mod;    
    }

    keys1[0] = s[0];
    for (int i = 1; i < n; i ++) {
        keys1[i] = (keys1[i - 1] * base) % mod + s[i];
        keys1[i] %= mod;        
    }

    keys2[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; i -- ) {
        keys2[i] = (keys2[i + 1] * base)%mod + s[i];
        keys2[i] %= mod;
    }
        
}


int get_sub_key1(int len, int cent) {
    int beg = cent - len;
    int fin = cent;
    if (beg == 0) return keys1[fin];
    return ((keys1[fin] - (keys1[beg - 1] * p[len + 1]) % mod)%mod + mod)%mod; 
}


int get_sub_key2(int len, int cent) {
    int fin = cent;
    int beg = cent + len;
    if (beg == n - 1) return keys2[fin]; 
    return ((keys2[fin] - (keys2[beg + 1] * p[len + 1]) % mod) % mod + mod)%mod;
}

bool is_same_odd(int len, int cent) {
    int key1 = get_sub_key1(len, cent);
    int key2 = get_sub_key2(len, cent);
    return key1 == key2;
}


int binary_search_odd(int cent) {
    
    int len_lo = 0;
    int len_hi = min(cent, n - 1 - cent);

    while (len_lo < len_hi) {
        int len_mid = (len_lo + len_hi + 1) / 2;

        bool ok = is_same_odd(len_mid, cent);
        if (ok) {
            len_lo = len_mid;
        }
        else {
            len_hi = len_mid - 1;
        }
    }

    return len_lo;
}

bool is_same_even(int len, int cent) {
    int key1 = get_sub_key1(len, cent);
    int key2 = get_sub_key2(len, cent + 1);
    return key1 == key2;
}


int binary_search_even(int cent) {
    int len_lo = 0;
    int len_hi = min(cent, n - 2 - cent);

    while (len_lo < len_hi) {
        int len_mid = (len_lo + len_hi + 1) / 2;

        bool ok = is_same_even(len_mid, cent);
        if(ok) {
            len_lo = len_mid;
        } else {
            len_hi = len_mid - 1;
        }
    }
    return len_lo;
}


signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    n = s.size();

    build();
 
    int mxlenodd = 0;
    int centodd = 0;
    for (int cent = 0; cent < n; cent ++) {
        int len = binary_search_odd(cent);
        if (len > mxlenodd) {
            mxlenodd = len;
            centodd = cent;
        }
    }
    

    int mxleneven = 0;
    int centeven = 0;
    for (int cent = 0; cent < n - 1; cent ++) {
        int len = binary_search_even(cent);    
        if (mxleneven < len) {
            mxleneven = len;
            centeven = cent;
        }
    }
    
    string ans = "";
    if (mxlenodd * 2 + 1 > mxleneven * 2 + 2) {
        for (int i = centodd - mxlenodd; i <= centodd + mxlenodd; i ++) {
            ans += s[i];
        }    
    } else {
        for (int i = centeven - mxleneven; i <= centeven + mxleneven + 1; i ++) {
            ans += s[i];
        }
    }
    cout << ans << endl;
    

    return 0;
}