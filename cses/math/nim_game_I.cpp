#include <bits/stdc++.h>
using namespace std;

#define nmax 200005
int t, n, x;


signed main() {

    cin >> t;
     
    
    while (t -- ) {
        cin >> n;


        int res = 0;
        for (int i = 0; i < n; i ++) {
            cin >> x;
            res ^= x;
        }

      
        if (res != 0) {
            cout << "first" << endl;
        }
        else {
            cout << "second" << endl;
        }



    }


    return 0;
}