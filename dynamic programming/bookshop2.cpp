#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18;

const int nmax = (int)1e2 + 1;
int n, x;
int price[nmax], pages[nmax], copies[nmax];

int dp[110][(int)1e5 + 10];


int solve(int id, int totprice) {
    
    if (totprice > x) return -inf;
    if (id == n) return 0;
   
    int res = dp[id][totprice];

    if (res != -1) return res;


    for (int i = 0; i <= copies[id]; i ++) {
        int tmp = solve(id + 1, totprice + (i * price[id])) + (i * pages[id]);
        res = max(res, tmp);
    }  

    return dp[id][totprice] = res;
}

void print(int id, int totprice) {

     if (totprice > x) return ;
     if ( id == n) return ;   

    for (int i = 0; i <= copies[id]; i ++) {
        int tmp = solve(id + 1, totprice + (i * price[id])) + (i * pages[id]);
        if ( tmp == dp[id][totprice]) {
            cout << id << " " << i << endl;
            print(id + 1, totprice + (i * price[id]));
            break;
        }
    }

}



signed main() {

    cin >> n >> x;
    for (int i = 0; i < n; i ++) { 
        cin >> price[i] >> pages[i] >> copies[i];
    }

    memset(dp, -1, sizeof dp);

    int res = solve(0, 0);
    cout << res << endl;

         
  //  cout << endl;
  //  print(0, 0);

    
    
    return 0;
}