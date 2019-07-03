#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
    
    int t, test = 0;
    cin >> t;
    while(t -- ) {
        string s;
        cin >> s;
        string a = "", b = "";
        
        bool two = false;
        for (int i = 0; i < s.size(); i ++) {
            if ( s[i] == '4') {
                a += "2";
                b += "2";
                two = true;
            } else {
                a += s[i];
                if ( two ) {
                    b += "0";
                }
            }
        }
        cout << "Case #" << ++test << ": " << a << " " << b << endl;
    }

    return 0;
}