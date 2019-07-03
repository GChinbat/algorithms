#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Comp {
    bool operator() (const int& x, const int& y) const {
        return x > y;
    }
};

signed main() {
     
    set<int > s;
    s.insert(12);
    s.insert(34);
    s.insert(0);
    s.insert(199);
    
    for (auto x : s) {
        cout << x << " ";
    } cout << endl;
    
    cout << s.count(12) << endl;
    cout << s.count(34) << endl;
    
    s.erase(12);
    s.insert(34);
    cout << s.count (12) << endl;
    cout << s.count(34) << endl;
    
    auto it = s.find(34);
    if ( it != s.end()) {
        cout << *it << endl;
        s.erase(it);
    }
    
    it = s.find(34);
    if ( it == s.end()) {
        cout << s.count(34) << endl;
    }
    
    set<int, Comp> myset;
    myset.insert(1);
    myset.insert(2);
    myset.insert(3);
    myset.insert(4);
    
    cout << endl;
    
    for (auto x : myset) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}