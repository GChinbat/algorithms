#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18 + 7



signed main() {
            
    unordered_set<int > uset;
    
    uset.insert(10);
    uset.insert(10);
    uset.insert(10);
    
    uset.insert(15);
    uset.insert(20);
    uset.insert(1);
    uset.insert(7);
    uset.insert(12);
    
    for (auto x : uset) {
        cout << x << " ";
    }
    cout << endl;
    

    auto it = uset.find(10);
    if ( it != uset.end()) {
        cout << *it << endl;
        uset.erase(it);
    }    
    it = uset.find(10);
    if ( it == uset.end()) {
        cout << "0" << endl;
    }
    
        
    return 0;
}