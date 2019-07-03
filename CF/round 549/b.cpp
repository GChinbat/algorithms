#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7

const int nmax = (int) 1e6 + 10;

int calc(vector<int > b) {
    
   // cout << "calc :: " << endl;
    for (auto x : b) {
   //     cout << x << " ";
    } //cout << endl;
    
    reverse(b.begin(), b.end());
    while(b.back() == 0) {b.pop_back();}
    int mul = 1;
   // cout << endl;
    reverse(b.begin(), b.end());
    for (auto x : b) {
    //    cout << x << " ";
        mul *= x;
    }
    //cout << endl;
    return mul;
}

signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int > a;
    while(n) {
        a.push_back(n%10);
        n /= 10;
    }
    
    reverse(a.begin(), a.end());
    
    int ans = calc(a);
    for (int i = 0; i < a.size(); i ++) {
        vector<int > b;
        for (int j = 0; j < i; j ++) {
            b.push_back(a[j]);
        }
        b.push_back(a[i] - 1);
        for (int j = i + 1; j < a.size(); j ++) {
            b.push_back(9);
        }
        ans = max(ans, calc(b));
    }
    cout << ans << endl;
    
    
    return 0;
}