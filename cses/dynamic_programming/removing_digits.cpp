#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18 + 7
#define mod 1000000007


const int nmax = (int)1e6 + 10;
int n;
int dp[nmax];

int solve(int rem) {

    if (rem == 0) return 0;    

    int x = rem;
    int& ans = dp[rem];
    if (ans != -1) return ans;

    ans = inf;
    while (x) {
        int num = x % 10;
        x/=10;
        if (rem -num >= 0)
            ans = min(ans, solve(rem - num) + 1);        
    }

    return ans;
}


signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    
    memset(dp, -1, sizeof dp);
    int res =  solve(n);

    cout <<res << endl;



    return 0;
}