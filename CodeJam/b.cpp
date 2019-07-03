#include <bits/stdc++.h>
using namespace std;


signed main() {
    int T, test = 0;
    cin >> T;
    while(T -- ) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string res = "";
        for(int i = 0; i < s.size(); i ++) {
            if ( s[i] == 'S') {
                res += "E";
            } else {
                res += "S";
            }
        }
        cout << "Case #" << ++test << ": " << res << endl;
    }

    return 0;
}