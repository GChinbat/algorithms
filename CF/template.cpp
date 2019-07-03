#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int nmax = (int) 1e6 + 10;




signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    string s;
    while(getline(cin, s)) {
        if (s.size() == 0) {continue;}
        string name = "";
        for (int i = 0; i < s.size(); i ++) {
           if (i == 0 && s[i] == ' ') continue;
           if ( s[i] == '.') continue;
           if ( '0' <= s[i] && s[i] <= '9') continue;
           name += s[i];
        }                    
        
        if ( name .size() == 0) continue;
        cout << name << endl;

            
    }

    
    return 0;
}