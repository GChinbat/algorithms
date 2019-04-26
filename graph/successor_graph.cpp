#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10
//########################//

const int nmax = (int) 1e6 + 10;


int n, m;


int succ[nmax];
int pow_succ[25][nmax];


void build() {
    for (int i = 1; i <= n; i ++) {
        pow_succ[0][i] = succ[i];
    }

    for (int i = 1; i < 25; i ++) {
        for (int j = 1; j <= n; j ++) {
            int pre = pow_succ[i - 1][j];
            pow_succ[i][j] = pow_succ[i - 1][pre];
        }
    }
}

int get_kth_successor(int beg, int kth) {

    if (kth == 0) return beg;    

    int p2 = 0;
    int pv = 1;
    while(true) {
        if (pv * 2 <= kth) pv *= 2, p2 ++;
        else break;
    }

    return get_kth_successor(pow_succ[p2][beg], kth - pv);
       
}


signed main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    freopen("in", "r", stdin);
    freopen("out", "w", stdout);


    cin >> n >> m;


    memset(succ, -1, sizeof succ);
    
    while( m -- ) {
      
        int from, to;
        cin >> from >> to;
        succ[from] = to;
    }

    for (int i = 1; i <= n; i ++) {
        cout << succ[i] << " ";
    }
    cout << endl;

    build();


    for (int i = 0; i < 25; i ++) {
        for (int j = 1; j <= n; j ++) {
            cout << pow_succ[i][j] << " ";
        }
        cout << endl;
    }
    int beg = 9;

    int kth;
    while(cin >> kth) {
        cout << get_kth_successor(beg, kth) << endl;
    }


                             

    return 0;
}