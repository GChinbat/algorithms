#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7
#define mod 1000000007

int p, n;
vector<int > s;


signed main() {
    int test, testno = 0;
    cin >> test;
    while(test --) {
        cin >> n >> p;
        s.clear();
        for (int i = 0; i < n; i ++) {
            int power;
            cin >> power;
            s.push_back(power);
        }    

        sort(s.begin(), s.end());

        int target = p;

        int sum = 0;
        for (int i = 0; i < p; i ++) {
            sum += s[p - 1] - s[i];    
        }

        int ans = sum;

        for (int i = p ; i < n; i ++) {
            sum -= (s[i - 1] - s[i - p]);
            sum += ((p - 1) * (s[i] - s[i - 1]));            
            ans = min(sum, ans);
        }

        cout << "Case "<< "#" << ++testno << ": " << ans << endl;
    
    }                       
    
    return 0;
}