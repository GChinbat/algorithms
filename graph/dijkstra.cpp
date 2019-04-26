#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7
#define mod 1000000007
#define mp make_pair
#define nod first
#define len second

typedef pair<int, int > pii;


const int nmax = (int)1e5 + 10;
vector<pair<int, int > > joint[nmax];

struct Comp {
    bool operator() (const pair<int,int >& a, const pair<int, int >& b) {
        return a.second > b.second;
    }
};


bool processed[nmax];
int dist[nmax];
int parent[nmax];
int n, m;


int dijkstra(int source, int dest) {
    
    priority_queue<pii, vector<pii >, Comp > Q;
    
    memset(processed, 0, sizeof processed);
    memset(dist, -1, sizeof dist);
    for (int i = 1; i <=n ; i++) {
        dist[i] = inf;
    }

    dist[source] = 0;
    Q.push(mp(source, 0LL));

    while(Q.size()) {
        pii from = Q.top(); Q.pop();
        if (processed[from.nod]) continue;
        processed[from.nod] = true;

        for (auto to : joint[from.nod]) {
            if (processed[to.nod]) continue;
            if ( dist[to.nod] > dist[from.nod] + to.len ) {
                dist[to.nod] = dist[from.nod] + to.len;
                Q.push(mp(to.nod, dist[to.nod]));
                parent[to.nod] = from.nod;    
            }            
        }
    }

    for (int i = 1; i <= n; i ++) {
        cout << "from " << source << " to " << dest << " distance is : " << dist[i] << endl;
    }

    return dist[dest];
}


void test () {

    priority_queue<pii, vector<pii>, Comp > Q;
    Q.push(mp(1, 2));
    Q.push(mp(1, 5));
    Q.push(mp(2, 3));
    Q.push(mp(9, 1));
    Q.push(mp(0, 23));

    while(Q.size()) {
        pii u = Q.top(); Q.pop();
        cout << u.nod << " " << u.len << endl;
    }

}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    test();

    cin >> n >> m;
    while(m -- ) {
        int u, v, w;
        cin >> u >> v >> w;
        joint[u].push_back(mp(v, w));
        joint[v].push_back(mp(u, w));

    }
    
    dijkstra(1, n);

    return 0;
}