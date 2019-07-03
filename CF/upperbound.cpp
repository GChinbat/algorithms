#include <bits/stdc++.h>
using namespace std;


signed main() {
                        
    vector<int > a = {1, 1, 1, 2, 2, 2, 5, 5, 5, 9, 10, 10, 15};
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < a.size(); i ++) {
        cout << i << " : " << a[i] << endl;
    }
    
    
    int tar;
    while( cin >> tar ) {
        
        auto it = upper_bound(a.begin(), a.end(), tar);
        cout << *it << endl;
        cout << "res : " <<  (int)(it - a.begin()) << endl << endl;
        cout << endl;
    }
    
    
    return 0;
}