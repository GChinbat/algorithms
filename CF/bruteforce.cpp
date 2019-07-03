#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int nmax = (int) 1e6 + 10;


int calc(string t, string s) {

    int cnt = 0;
    for (int i = 0; i < t.size(); i ++) {
        for (int j = i; j < t.size(); j ++) {
            string tmps = "";
            string tmpt = "";
            for (int k = i; k<= j; k ++) {
                tmps += s[k];
                tmpt += t[k];
            }
            if (tmpt > tmps) {
               cnt ++;
            }
        }
    }    
    return cnt;

}


signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    freopen("out", "w", stdout);

    string s = "abcd";

    vector<string > all;

    for (int a = 'a'; a <= 'z'; a ++) {
        for (int b = 'a'; b <= 'z'; b ++) {
            for (int c = 'a'; c <= 'z'; c ++) {
                for (int d = 'a'; d<= 'z'; d++) {
                    string aa = "";
                    aa += a;
                    aa += b;
                    aa += c;
                   aa += d;
                    all.push_back(aa);
                    
                }
           }
        }
    }

    
    int dp[100][100];
    memset(dp, 0, sizeof dp);
    
    for(auto t : all) {
       int res = calc(t, s);
       if (res == 1  && t[0] == s[0]) {
        cout << t << endl;
       }
       if (res > 7) continue;
       dp[s.size()][res] ++;            
    }
    
    for (int i = 0; i <= 7; i ++) {
        cout << dp[s.size()][i] << " ";

    }  cout << endl;

    

    
    return 0;
}