#include <bits/stdc++.h>
using namespace std;

#define nmax 100005
#define city second
#define cost first
#define mp make_pair
#define pb push_back
#define int long long
#define inf (int)1e18+7


typedef pair<int, int > pii;
typedef pair<int, pii > tii;


int n, m;
vector<pair<int, int > > graph[nmax];

vector<int > dist[2], isout[2];


void dijkstra() {

    priority_queue<tii > Q;
    
    dist[0].assign(n + 1, inf);
    dist[1].assign(n + 1, inf);
    isout[0].assign(n + 1, false);
    isout[1].assign(n + 1, false);
    Q.push(mp(0, mp(0, 1)));
    dist[0][1] = 0;
    
   


    while (Q.size()) {
        tii ttt = Q.top(); Q.pop();
        int u = ttt.second.second;
        int coupon = ttt.second.first;
        if (isout[coupon][u]) continue;

        for (auto v : graph[u]) {
            if (coupon == 1) {
                dist[1][v.city] = min(dist[1][v.city], dist[1][u] + v.cost);                    
                Q.push(mp(-dist[1][v.city], mp(1, v.city)));
            } else {
                dist[0][v.city] = min(dist[0][v.city], dist[0][u] + v.cost);
                Q.push(mp(-dist[0][v.city], mp(0, v.city)));
                dist[1][v.city] = min(dist[1][v.city], dist[0][u] + v.cost / 2);
                Q.push(mp(-dist[1][v.city], mp(1, v.city)));
            }    
        }
        isout[coupon][u] = true;                  
    }

    return ;
}


signed main() {

    cin >> n >> m;
    while (m --) {
        int from, to, price;
        cin >> from >> to >> price;
        graph[from].pb(mp(price, to));
    }

    dijkstra();

    cout << min(dist[0][n], dist[1][n]) << endl;


    return 0;
}