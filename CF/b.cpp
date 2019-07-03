#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18 + 10
#define pb push_back
#define mp make_pair

const int nmax = (int)1e5 + 10;

int n, m;
vector< int > graph[nmax];
int par[nmax][30];
int deep[nmax];

void dfs(int u, int p) {

    par[u][0] = p;
    deep[u] = deep[p] + 1;
    for (auto& v : graph[u]) {
        if ( v == p) continue;
        dfs(v, u);
    }    

}

void build() {
    
    for (int i = 1; (1 << i) <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }

}


int get_kth(int u, int k) {
    
    while (k > 0) {
        int i = 0;
        for (; (1 << i) <= k; i ++) {}
        i --;
        u = par[u][i];
        k -= (1 << i);
     }

   return u;
}


int get_lca(int u, int v) {
    
    if (deep[u] > deep[v]) swap(u, v);
    
    int dif = deep[v] - deep[u];
    
    v = get_kth(v, dif);
    
    if ( u == v) {
        return u;
    }

    int k = deep[u] - 1;

    while ( k > 0 ) {
        int i = 0;
        for (; (1 << i) <= k; i ++) {}
        i --;
        
        int uu = par[u][i];
        int vv = par[v][i];
        if ( uu == vv) {
            k = (1 << i) - 1;    
        } else {
            k -= (1 << i);
            u = uu;
            v = vv;  
        }                        
    }
    
    return par[u][0];
}


int get_dist(int u, int v) {
    
    return deep[u] + deep[v] - 2 * deep[get_lca(u, v)];

}


int sub[nmax];

void calc_sub(int u, int p) {
    
    sub[u] = 1;
    for (auto& v : graph[u]) {
        if (v == p) continue;
        calc_sub(v, u);
        sub[u] += sub[v];
    }

}


int get_centroid(int u, int p, int nn) {
    
    for (auto& v : graph[u]) { 
        if (v == p) continue;
        if (sub[v] <= nn / 2) continue;
        return get_centroid(v, u, nn);    
    }

    return u;
}


int centroid_par[nmax];

vector<int > level[nmax];

void decompose(int u, int p, int le) {

    calc_sub(u, 0);
    int centroid = get_centroid(u, p, sub[u]);

    centroid_par[centroid] = p;
    level[le].push_back(centroid);

    for (auto& uu : graph[centroid]) {

        for (auto& v : graph[uu]) {
            if ( v == centroid) {
                swap(v, graph[uu].back());
                graph[uu].pop_back();
                break;
            }
        }

        decompose(uu, centroid, le + 1);     
    }

    graph[centroid].clear();

}


vector<int > ans;


void update(int u) {
    int r = u;
    while (true) {
        ans[u] = min(ans[u], get_dist(r, u));
        u = centroid_par[u];
        if (u == 0) break;
    }    
}

int query(int u) {
    
    int x = u;
    int res = inf;
    while(true) {
        res = min(res, get_dist(x, u) + ans[u]);   
        u = centroid_par[u];
        if ( u == 0) break;
    }

    return res;
}




signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    
    cin >> n >> m;
    int nn = n - 1;
    while ( nn -- ) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);

    }

    
    dfs(1, 0);
    build();
    
    decompose(1, 0, 0);


   
    ans.assign(n + 1, inf);

    update(1);

   
    while ( m -- ) {
        int dir, node;
        cin >> dir >> node;

        if (dir == 1) {
            update(node);
        } 
        else {
            cout << query(node) << endl;
        }
         
    }
    
    return 0;
}