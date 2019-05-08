#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7
#define mod 1000000007
#define node first
#define len second
#define mp make_pair



const int nmax = (int)1e5 + 10;
typedef pair<int, int > pii;
vector<pii > joint[nmax];


struct Comp {
    bool operator() (const pii& a, const pii& b) const {
        return a.len > b.len;    
    }
};


int solve(int root, int n) {
    
    priority_queue<pii, vector<pii>, Comp > Q;
    vector<bool > in(n + 1, false);
    
    for (auto p : joint[root]) {
        Q.push(p);
    }
    in[root] = true;
    int ans = 0;

    while(Q.size()) {
        pii p = Q.top(); Q.pop();
       
        if (in[p.node]) continue;
        ans += p.len;
        for (auto pp : joint[p.node]) {
            if (in[pp.node]) continue;
            Q.push(pp);
        }
        in[p.node] = true;
    } 

    return ans;
}



signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    freopen("in", "r", stdin);

    int n, m;
    cin >> n >> m;
    while (m -- ){
        int u, v, w;
        cin >> u >> v >> w;
        joint[u].push_back(mp(v, w));
        joint[v].push_back(mp(u, w));
    }

    int ans = solve(1, n);
    cout << ans << endl;
   
    return 0;
}