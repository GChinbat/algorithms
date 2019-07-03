#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10

const int nmax = (int)2e5+ 10;


int n;
pair<int, int > task[nmax];

signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    #define dura first
    #define dead second
    for (int i = 0; i < n; i ++) {
        cin >> task[i].dura >> task[i].dead;    
    }


    sort(task, task + n);

    int ans = 0;
    int pre = 0;
    for (int i = 0; i < n; i ++) {
        pre += task[i].dura;
        ans += (task[i].dead - pre);    
    }
    cout << ans << endl;
                        

    return 0;
}