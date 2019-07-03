#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10

int n, m, q;

int graph[555][555];


signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;
    

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if ( i == j) graph[i][j] = 0;
            else graph[i][j] = inf;
        }
    }
    
    
    while ( m -- ) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u][v] = min(graph[u][v], c);
        graph[v][u] = min(graph[v][u], c);
    }




    for (int k = 1; k <= n; k ++) {
        for (int u = 1; u <= n; u ++) {
            for (int v = 1; v <= n; v ++) {
                graph[u][v] = min(graph[u][v], graph[u][k] + graph[k][v]);                      
            }
        }
    }

    while (q -- ) {
        int beg, fin;
        cin >> beg >> fin;
        if (graph[beg][fin] == inf) {
            graph[beg][fin] = -1;
        }
        cout << graph[beg][fin] << endl;
    }





    return 0;
}