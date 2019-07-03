#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
set<int > s;

vector<int > dif;
vector<int > prefix, pre;

signed main() {
    
    cin >> n;
    for (int i = 0; i < n;i  ++) {
        int aa;
        cin >> aa;
        s.insert(aa);
    }    
    
    vector<int > a;
    for (auto it:s) {
        a.push_back(it);
    }
        
    for (int i = 1; i < a.size(); i ++) {
        dif.push_back(a[i] - a[i - 1] - 1);
    }
    sort(dif.begin(), dif.end());
    prefix.push_back(0);
    pre.push_back(0);
    for (int i = 0; i < dif.size();i  ++) {
        prefix.push_back(prefix.back() + dif[i]);
        pre.push_back(pre.back() + 1);
    }
    
    vector<int > ans;
    int q;
    cin >> q;
    while( q -- ) {
        int u, v;
        cin >> u >> v;
        v -= u;
        auto it = lower_bound(dif.begin(), dif.end(), v);
        int pos = (int)(it - dif.begin());
        
        int res = a.back() - a[0] + 1 + v;
        int tmp = (prefix.back() - prefix[pos]);
        int tmp1 = (pre.back() - pre[pos]);
        res = res - (tmp - tmp1 * v);
        ans.push_back(res);
    }
    for (auto f : ans) {
        cout << f << " ";
    } cout << endl;
    
    
    return 0;
}