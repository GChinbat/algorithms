#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007
const int nmax = 30005;
    

class Solution {
public:

    int precnt[nmax], poscnt[nmax];
    vector<pair<int, int > > pre;
    vector<pair<int, int > > pos;

    int sumSubarrayMins(vector<int>& a) {
        
        reverse(a.begin(), a.end());
        a.push_back(0);
        reverse(a.begin(), a.end());
        a.push_back(0);
        
        pre.pb(mp(0, 0));
        for (int i = 1; i < a.size() - 1; i ++) {
            while(pre.size()) {
                pair<int, int > p = pre.back();
                if ( p.first >= a[i]) {
                    pre.pop_back();
                } else {
                    precnt[i] = i - p.second;
                    pre.push_back(mp(a[i], i));
                    break;
                }            
            }                                
        }

        pos.push_back(mp(0, a.size() -1));
        for (int i = a.size() - 2; i > 0 ; i --) {
             while(pos.size()) {
                pair<int, int > p = pos.back();
                if ( p.first > a[i]) {
                    pos.pop_back();
                } else {
                    poscnt[i] = p.second - i;
                    pos.push_back(mp(a[i], i));
                    break;
                }            
            }
        }

        int ans = 0;
        for (int i = 1; i < a.size() -1; i ++) {
            cout << precnt[i] << " " << poscnt[i] << " " << a[i] << endl;
            int tmp = (precnt[i] * poscnt[i]) % mod;
            tmp *= a[i];
            tmp %= mod;
            ans += tmp;
        }
        cout << ans << endl;
        
        return ans;
    }



};


signed main() {
    ios_base :: sync_with_stdio(false);
    
    Solution sol;
    vector<int > aa = {71,55,82,55};
    int res = sol.sumSubarrayMins(aa);
    cout << res << endl;

    return 0;
}