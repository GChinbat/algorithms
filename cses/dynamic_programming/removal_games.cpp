#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7


int a[5555];



pair<int, int > solve(int id, int first, int last) {

     max( res, solve(first, last - 1) + a[last]  );
     max( res, solve(first + 1, last) + a[first] );
    
    return res;
}


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;

    for (int i = 0 ;i < n; i ++) {
        cin >> a[i];
    }



    return 0;
}