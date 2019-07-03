#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define pb push_back

int n, m, w[N] = {0};
vector<int > g[2][N], t;


void d(int u, int id) {
    w[u] = 1;
    for (auto v : g[id][u]) {
        if (w[v] == 0) {
            d(v, id);
        }
    }
    t.pb(u);
}


int main() {
    scanf("%d%d", &n, &m);
    while (m -- ) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[0][u].pb(v);
        g[1][v].pb(u);
    }    

    for (int i = 1; i <= n; i ++) 
        if (!w[i]) d(i, 1);
    
        
   
    memset(w, 0, sizeof w);

    int s = t.back();
    t = {};

    d(s, 0);

    if (t.size() == n) puts("YES");
    else {
        puts("NO");
        
        for (int i = 1; i <= n; i ++)
            if (w[i] == 0) {
                printf("%d %d", t.back(), i);
                break;
            }
    }
       
    return 0;
}