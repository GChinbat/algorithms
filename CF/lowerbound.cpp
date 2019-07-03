#include <bits/stdc++.h>
using namespace std;


signed main() {
                        
    vector<int > a = {0, 0, 1, 3};
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < a.size(); i ++) {
        cout << i << " : " << a[i] << endl;
    }
    
    
    int tar;
    while( cin >> tar ) {
        
        auto it = lower_bound(a.begin(), a.end(), tar);
        cout << *it << endl;
        cout << "res : " <<  (int)(it - a.begin()) << endl << endl;
        cout << endl;
    }
    
    
    return 0;
}