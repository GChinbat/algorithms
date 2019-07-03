#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    multiset<int > mset;
    mset.insert(3);
    mset.insert(3);
    mset.insert(5);
    mset.insert(1000);
    mset.insert(4);
    mset.insert(5);
    
    cout << endl;
    for (auto x : mset) {
        cout << x << " "  << endl; 
    }
    cout << endl;
    
    cout << mset.count(3) << endl;
    
    mset.erase(3);
    cout << mset.count(3) << endl;
    
    for (int i = 0; i < 5; i ++) {
        mset.insert(3);
    }
    
    cout << mset.count(3) << endl;
    
    mset.erase(mset.find(3));
    cout << mset.count (3) << endl;
    

    return 0;
}
