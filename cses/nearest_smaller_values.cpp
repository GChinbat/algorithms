#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7

const int nmax = (int)2e5 + 10;
int n, x[nmax];


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> x[i];
    }

    #define pos first
    #define val second

    stack<pair<int, int > > st;

    vector<int > ans;
    for (int i = 0; i < n; i ++) {

        while(st.size()) {
           pair<int, int > p = st.top();
           if (p.val >= x[i]) {
                st.pop();
           } else {
             break;
           }           
        }

        if (st.size() == 0) {
            ans.pb(0);
        }
        else {
            
            ans.pb(st.top().pos);
        
        }

        st.push(mp(i + 1, x[i]));
    
    }
    
    for (int i = 0; i < n; i ++) {
        cout << ans[i] << " ";
    }
    cout << endl;



    return 0;
}