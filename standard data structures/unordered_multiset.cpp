#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18

signed main() {
    
    unordered_multiset<int > umset;
    umset.insert(10);
    umset.insert(10);
    umset.insert(10);
    umset.insert(10);
    umset.insert(2);
    umset.insert(8);
    umset.insert(1);
    umset.insert(12);
    umset.insert(12);
    umset.insert(12);
    
    cout << endl;
    for (auto x : umset ) {
        cout << x << " ";
    } cout << endl;
    
    
    cout << umset.count(12) << endl;
    umset.erase(12);
    cout << umset.count(12) << endl;
    
    cout << endl;
    cout << umset.count(10) << endl;
    umset.erase(umset.find(10));
    cout << umset.count(10) << endl;
    
    auto range = umset.equal_range(10);
    
    cout << endl;
    for (auto it = range.first; it != range.second; it ++) {
        cout << *it << " ";
    } cout << endl;
    
    
    
    
    return 0;
}