#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int p[50], r[5];

pair<int, int > get_prize(int points) {
    pair<int , int > res(-1, 0);
    for (int i = 4; i >= 0; i --) {
        if ( points >= r[i]) {
            res.first = i;
            res.second = points / r[i];
            break;
        }
    }
    return res;
}

signed main() {
    
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> p[i];
    }
    
    for (int i  =0 ; i < 5; i ++) {
        cin >> r[i];
    }
    
    int rem = 0;
    int ans[5] = {0};
    for ( int i = 0; i < n; i ++) {
        rem += p[i];
        
        while(true) {
            pair < int ,int > res = get_prize(rem);
            if ( res.first != -1) {
                ans [res.first] += res.second;
                rem -= r[res.first] * res.second;
            } else {
                break;
            }
        }
    }
    
    for (int i = 0; i < 5; i ++) {
        cout << ans[i] << " ";
    } cout << endl;
    cout << rem << endl;
    
    return 0;
}