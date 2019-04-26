#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define fi first
#define se second



const int nmax = (int)1e5 + 10;
struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    void init(int u, int v, int w) {
        this->u = u; this -> v = v; this -> w = w;
    }
};
vector<Edge> edges;
vector<pair<int, int > > joint[nmax];
int n, m;

int dist[nmax];   


int get_shortest_dist(int source, int dest) {
    
    
    int mm = n - 1;
    
    for (int i = 1; i <= n; i ++) {
        dist[i] = inf;
    }

    dist[source] = 0;


    while(mm --) {
        for (auto edge : edges) {
            dist[edge.v] = min(dist[edge.v], dist[edge.u] + edge.w);        
        }
    }
    
    for(int i = 1; i <= n; i ++) {
        cout << "from " << source << " to dest " << dest << " distance is : " << dist[i] << endl; 
    }

    return dist[dest];
}


int get_shortest_dist2(int source, int dest) {
    
    int mm = n - 1;
    for (int i = 1; i <= n; i ++) {
        dist[i] = inf;
    }
    while(mm --) {

        for (int from = 1; from <= n; from ++) {
            for (auto to : joint[from]) {
                dist[to.fi] = min(dist[to.fi], dist[from] + to.se); 
            }
        }
        
    }

    for(int i = 1; i <= n; i ++) {
        cout << "from " << source << " to dest " << dest << " distance is : " << dist[i] << endl;
    }

    return dist[dest];

}


bool has_negative_cycle(int source) {

    int mm = n - 1;
    for (int i = 1; i <=n ;i ++) {
        dist[i] = inf;
    }

    while ( mm --) {
        for( int from = 1; from <= n; from ++) {
            for (auto to : joint[from]) {
                dist[to.fi] = min(dist[to.fi], dist[from] + to.se);
            }
        }   
    }

    for (int from = 1; from <= n; from ++) {
        for (auto to : joint[from]) {
            if ( dist[to.fi] > dist[from] + to.se) {
                return true;
            }
        }    
    }

    return false;

}

int parent[nmax];


vector<int > get_shortest_path(int source, int dest) {    

    memset(parent, -1, sizeof parent);
    
    for (int i = 1; i <= n; i ++) {
        dist[i] = inf;
    }
    
    dist[source] = 0;
    int mm = n - 1;
    while( mm -- ) {
        
        for (auto edge : edges) {
            
            if (dist[edge.v] > dist[edge.u] + edge.w) {
                parent[edge.v] = edge.u;
                dist[edge.v] = dist[edge.u] + edge.w;
            }
            
        }            

    }
   

    vector<int > path;
    int node = dest;
    while(true) {

        if (node == -1) break;
        path.pb(node);
        node = parent[node];
        
    }

    reverse(path.begin(), path.end());
    cout << "shortest path is :: "; 
    for (auto node : path) {
        cout << node << " -> ";
    } cout << endl;


    return path;
}

void initialize() {
    cin >> n >> m;
    while (m -- ) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge edge(u, v, w);
        edges.pb(edge);
        edge.init(v, u, w);
        edges.pb(edge);
        
        joint[u].pb(mp(v, w));
        joint[v].pb(mp(u, w));
    }
}

void testing() {
    n = 5;
    m = 7;
    
    edges.clear();
    Edge edge(0, 0, 0);
    
    edge.init(1, 2, 2);
    edges.pb(edge);
    edge.init(1, 4, 7);
    edges.pb(edge);
    edge.init(1, 3, 3);
    edges.pb(edge);

    edge.init(2, 1, 2);
    edges.pb(edge);
    edge.init(2, 4, 3);
    edges.pb(edge);
    edge.init(2, 5, 5);
    edges.pb(edge);

    edge.init(3, 1, 3);
    edges.pb(edge);
    edge.init(3, 4, 1);
    edges.pb(edge);

    edge.init(4, 1, 7);
    edges.pb(edge);
    edge.init(4, 2, 3);
    edges.pb(edge);
    edge.init(4, 3, 1);
    edges.pb(edge);
    edge.init(4, 5, 2);
    edges.pb(edge);

    edge.init(5, 2, 5);
    edges.pb(edge);
    edge.init(5, 4, 2);
    edges.pb(edge);

    get_shortest_path(1, 5);
    get_shortest_dist(1, 5);

}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); 

    
    //initialize();

    testing();

    
    return 0;
}