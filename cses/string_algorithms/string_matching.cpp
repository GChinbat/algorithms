#include <bits/stdc++.h>
using namespace std;

#define int long long
#define base 257
#define mod 1000000007
#define nmax 1000010

int p[nmax];

pair<int, int > build(string s1, string s2) {

    int n = s2.size();

    p[0] = 1;
    for (int i = 1; i <= n; i ++) {
        p[i] = p[i - 1] * base;
        p[i] %= mod;
    }
    
    int _key2 = 0;
    int _key1 = 0;
    for (int i = n - 1; i >= 0; i -- ) {
        _key2 += (p[n - i - 1] * s2[i]) % mod;
        _key2 %= mod;
        _key1 += (p[n - i - 1] * s1[i]) % mod;
        _key1 %= mod;             
    }
    
    return make_pair(_key1, _key2);
}


int get_new_key(int source_key, int ch_sub, int ch_add, int n) {
    
    int res = (((source_key * base) % mod + ch_add) % mod - (ch_sub * p[n]) % mod) % mod;
    if (res < 0) {
        res += mod;
        res %= mod;
    }    
    return res;

}


signed main() {

    string s1;
    string s2;
    cin >> s1 >> s2;

    pair<int, int > keys = build(s1, s2);

    int target_key = keys.second;
    int source_key = keys.first;

    
    int n1 = s1.size();
    int n2 = s2.size();

    int ans = target_key == source_key; 
    for (int i = n2; i < n1; i ++) {
        source_key = get_new_key(source_key, s1[i - n2], s1[i], n2);
        ans += (target_key == source_key);
    }
    cout << ans << endl;


    return 0;
}