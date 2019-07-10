#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define nmax 100005
#define cost first
#define node second
#define int long long
#define inf (int)1e18+7
#define mod 1000000007

typedef pair<int, int > pii;

int n, m;
vector< pii > graph[nmax];


int dijkstra_1() {
    priority_queue<pii > Q;
    
    vector<int > dist(n + 1, inf);
    vector<bool > out(n + 1, 0);

    Q.push(mp(0, 1));
    dist[1] = 0;
    
    while (Q.size()) {
        pii pu = Q.top(); Q.pop();

        if (out[pu.node]) continue;

        for (auto pv : graph[pu.node]) {
            int pre = dist[pv.node];
            dist[pv.node] = min(dist[pv.node], dist[pu.node] + pv.cost);
            if (pre != dist[pv.node]) {
                Q.push(mp(-dist[pv.node], pv.node));
            }
        }
    
        out[pu.node] = true;
    }

    return dist[n];
}

int dijkstra_2() {
    
    priority_queue<pii > Q;
    
    vector<pii > dist(n + 1, mp(inf, 1));
    vector<bool > out(n + 1, 0);

    Q.push(mp(0, 1));
    dist[1] = mp(0, 1);

    while (Q.size() ) {
        pii pu = Q.top(); Q.pop();
        if (out[pu.node]) continue;
        for (auto pv : graph[pu.node]) {
            if (dist[pv.node].cost > dist[pu.node].cost + pv.cost) {
                dist[pv.node].cost = dist[pu.node].cost + pv.cost;
                dist[pv.node].second = dist[pu.node].second;    
                Q.push(mp(-dist[pv.node].cost, pv.node));
            }else if (dist[pv.node].cost == dist[pu.node].cost + pv.cost) {
                dist[pv.node].second += dist[pu.node].second;
                dist[pv.node].second %= mod;
            }
        }
        out[pu.node] = true;
    }                             
    return dist[n].second;
}

int dijkstra_3() {
    priority_queue<pii > Q;
    vector<pii > dist(n + 1, mp(inf, 0));
    vector<bool > out(n + 1, 0);

    Q.push(mp(0, 1));
    dist[1] = mp(0, 0);

    while (Q.size() ) {
        pii pu = Q.top(); Q.pop();
        if (out[pu.node]) continue;
        for (auto pv : graph[pu.node]) {
            if (dist[pv.node].cost > dist[pu.node].cost + pv.cost) {
               dist[pv.node].cost = dist[pu.node].cost + pv.cost;
               dist[pv.node].second = dist[pu.node].second + 1;
               Q.push(mp(-dist[pv.node].cost, pv.node));             
            } else if (dist[pv.node].cost == dist[pu.node].cost + pv.cost) {
                if (dist[pv.node].second > dist[pu.node].second + 1) {
                     dist[pv.node].second = dist[pu.node].second + 1;   
                }
            }
        }
        out[pu.node] = true;
    }
    return dist[n].second;
}

int dijkstra_4() {
    priority_queue<pii > Q;
    vector<pii > dist(n + 1, mp(inf, 0));
    vector<bool > out(n + 1, 0);

    Q.push(mp(0, 1));
    dist[1] = mp(0, 0);

    while (Q.size() ) {
        pii pu = Q.top(); Q.pop();
        if (out[pu.node]) continue;
        for (auto pv : graph[pu.node]) {
            if (dist[pv.node].cost > dist[pu.node].cost + pv.cost) {
               dist[pv.node].cost = dist[pu.node].cost + pv.cost;
               dist[pv.node].second = dist[pu.node].second + 1;
               Q.push(mp(-dist[pv.node].cost, pv.node));             
            } else if (dist[pv.node].cost == dist[pu.node].cost + pv.cost) {
                if (dist[pv.node].second < dist[pu.node].second + 1) {
                     dist[pv.node].second = dist[pu.node].second + 1;   
                }
            }
        }
        out[pu.node] = true;
    }
    return dist[n].second;
}





signed main() {

    cin >> n >> m;
    while ( m -- ) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].pb(mp(c, v)); 
    }

    int ans_1 =  dijkstra_1();
    cout << ans_1 << " ";
    int ans_2 = dijkstra_2();
    cout << ans_2 << " ";
    int ans_3 = dijkstra_3();
    cout << ans_3 << " ";
    int ans_4 = dijkstra_4();
    cout << ans_4 << endl;
    return 0;
}