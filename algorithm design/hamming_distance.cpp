#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define mod 1000000007
#define inf (int)1e18+7


int hamming(string a, string b) {
    assert(a.size() == b.size());

    int diff = 0;
    for (int i = 0; i < a.size(); i ++) {
        diff += (a[i] != b[i]);
    }

    return diff;
}


int hamming_bit(string a, string b) {
    bitset<10> aa, bb;
    aa = bitset<10>(a);
    bb = bitset<10>(b);
    
    // cout << aa << " " << bb << endl;
    // int aaa = aa.to_ullong();
    // int bbb = bb.to_ullong();
    // return __builtin_popcount(aaa ^ bbb);
    // return (aa ^ bb).count();
    
    bitset<10 > cc = aa ^ bb;
    return cc.count();
}




signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    string vals[] = {"00111","01101","11110"};
    int n = 3;

    
    int min_hamm = inf;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            min_hamm = min(min_hamm, hamming(vals[i], vals[j]));
        }
    }
    
    cout << min_hamm << endl;

    min_hamm = inf;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            min_hamm = min( min_hamm, hamming_bit(vals[i], vals[j]));
        }
    }
    cout << min_hamm << endl;
    

    return 0;
}