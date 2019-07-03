#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10

const int nmax = (int)1e5 + 10;

int n, m;
vector<int > graph[nmax];
int color[nmax];
bool ok = true;


void dfs(int u ) {

    if (!ok) return ;
    for (auto v : graph[u]) {
        if (color[v] == 0) {
            color[v] = 3 - color[u];
            dfs(v);
        } else {
            if (color[v] == color[u]) {
               ok = false;
               return ; 
            }
        }
    }    
}


signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    while ( m -- ) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    
    memset(color, 0, sizeof color);

    for (int i = 1; i <= n; i ++) {
        if (color[i] == 0) {
            color[i] = 1;
            dfs(i);
        }
    }
   
    if (!ok) {
        puts("IMPOSSIBLE");
    } else {
        for (int i = 1; i <= n; i ++) {
            cout << color[i] << " ";
        }
        cout << endl;
    } 



    return 0;
}