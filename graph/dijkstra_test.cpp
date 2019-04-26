#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7
#define mod 1000000007
#define pb push_back

typedef vector<pair<int, int >> vii;
typedef pair<int, int > pii;

#define node first
#define len second
#define mp make_pair

struct Comp {
    bool operator() (const pii& a, const pii& b) const {
        return a.len > b.len;
    }
};


class Dijkstra {
    
    int n;
    
    public :
    vector< vii > joint;
    Dijkstra(int n) : n(n) {
        joint.assign(n + 1, vii());
    }

    int get_shortest_path(int beg, int fin) {
        priority_queue< pii , vector<pii>, Comp > Q;
        vector<int > dist(n + 1, inf);
        vector<bool > processed(n + 1, 0);

        dist[beg] = 0;
        Q.push(mp(beg, 0));

        while(Q.size()) {
            pii from = Q.top(); Q.pop();
            if ( processed[from.node] ) continue;
            if ( from.node == fin) {
                break;
            }
            for (auto to : joint[from.node]) {
                if ( processed[to.node] ) continue;
                dist[to.node] = min(dist[to.node], dist[from.node] + to.len);
                Q.push(mp(to.node, dist[to.node]));
            }
            processed[from.node] = true;
        }
        return dist[fin];
    }
        
};

signed main() {
    
    int test;
    cin >> test;
    while(test --) {
        int n, m;
        cin >> n >> m;
        Dijkstra dij(n);

        while (m -- ) {
            int from, to, len;
            cin >> from >> to >> len;
            dij.joint[from].pb(mp(to, len));
           // dij.joint[to].pb(mp(from, len));
        }

        int beg, fin;
        cin >> beg >> fin;
        int ans = dij.get_shortest_path(beg, fin);
        if (ans == inf) puts("NO");
        else cout << ans << endl;
    
    }
    
    return 0;
}