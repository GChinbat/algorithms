#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define nmax 2505
#define int long long
#define inf (int)1e18+7
#define node first
#define val second


int n, m;

vector<pair<int, int > > graph[nmax];
int indeg[nmax], incnt[nmax];
vector<int > dist, parent;
bool used[nmax];


void find_cycle(int u) {
    
    vector<int > path;
    int t = u;
    memset(used, 0, sizeof used);
    while (true) {
        path.pb(u);
        used[u] = true;
        u = parent[u];
        if (used[u] == true) {
            t = u;
            break;
        }
    }

    

    reverse(path.begin(), path.end());

    while (path.back() != t) {
          path.pop_back();
    }


    cout << "YES" << endl;
    cout << path.back() << " ";
    for (auto p : path) {
        cout << p << " ";
    }
        
}


void SPFA(int source) {

    vector <int > inque(n + 1, 0);
    dist.assign(n + 1, inf);
    parent.assign(n + 1, -1);
    memset(incnt, 0, sizeof incnt);

    queue<int > Q;
    Q.push(source);
    inque[source] = true;
    incnt[source] ++;
    dist[source] = 0;

    while (Q.size()) {
        int u = Q.front(); Q.pop();
        inque[u] = false;

        if (incnt[u] > n - 1) {
            find_cycle(u);
            return ;            
        }

        for (auto v : graph[u]) {
            if (dist[v.node] > dist[u] + v.val) {
                dist[v.node] = dist[u] + v.val;
                if (inque[v.node] == false) {
                    Q.push(v.node);
                    inque[v.node] = true;
                    incnt[v.node] ++;
                }
                parent[v.node] = u;
            }        
        }
    }

    cout << "NO" << endl;
    return ;
}



signed main() {

    cin >> n >> m;

    memset(indeg, 0, sizeof indeg);
    while ( m -- ) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].pb(mp(v, w));
        indeg[v] ++;
    }

    for (int i = 1; i <= n; i ++) {
        graph[0].pb(mp(i, 0));
    }
    SPFA(0);
    
    return 0;
}