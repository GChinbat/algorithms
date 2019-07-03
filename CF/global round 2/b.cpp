#include <bits/stdc++.h>
using namespace std;
#define int long long


bool isfit(multiset<int > ss, int h) {
    int sum = 0;
    vector<int > tmp;
    for (auto it: ss) {
        tmp.push_back(it);
    }
    reverse(tmp.begin(), tmp.end());
    for (int i = 0; i < tmp.size(); i += 2) {
        sum += tmp[i];
    }
    return sum <= h;
}

signed main() {
        
    int n, h;
    int a[1003];
    cin >> n >> h;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    
    multiset<int > ss;
    
    int ans = -1;
    for (int i = 0; i < n;i  ++) {
        ss.insert(a[i]);
        bool ok = isfit(ss, h);
        if (ok) ans = i + 1;
        else break;
    }
    
    cout << ans << endl;
    
    return 0;
}