// detecting connected components
// detecting has cycle
// is bipartite
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
const int nmax = (int)1e5 + 10;

typedef vector<int > vi;

int n, m;

vector<int > joint[nmax];
int dist[nmax];
int visited[nmax];
vector<int > component;


void bfs(int source) {
    queue<int > Q;
    memset(dist, -1, sizeof dist);
    
    visited[source] = true;
    dist[source] = 0;
    Q.push(source);
    component.push_back(source);

    while(Q.size() ) {
        int u = Q.front(); Q.pop();
        for (auto v : joint[u]) {
            if (visited[v]) continue;
            Q.push(v);
            visited[v] = true;
            component.push_back(v);
            dist[v] = dist[u] + 1;
        }
    }
}


vector<vi > get_all_components() {
    
    vector<vi > components;
    memset(visited, 0, sizeof visited);
    for (int i = 1; i <= n; i ++) {
        if (visited[i]) continue;
        
        component.clear();
        bfs(i);
        components.push_back(component);
    }

    int numb = 0;
    for (auto comp : components) {
        cout << "component #" << ++ numb << ": ";
        for (auto u : comp) {
            cout << u << ", ";
        }
        cout << endl;
    }

    return components;
} 

map<int, vi> get_level_elements() {
    
    memset(visited, 0, sizeof visited);
    bfs(1);
    
    map<int, vi> levels;

    for (int i = 1; i <= n; i ++) {
        levels[dist[i]].push_back(i);
    }

    for (auto level : levels) {
        cout << level.first << " :: ";
        for (auto u : level.second) {
            cout << u << ", ";
        }
          cout << endl;
    }


    return levels;
}

bool has_cycle() {
    
    vector<vi > comps = get_all_components();
    for (auto comp : comps ) {
        int nn = comp.size();
        int degree = 0;
        for (auto u : comp) {
            degree += joint[u].size();        
        }
         
        if ( degree / 2 > nn - 1) {
            cout << "yes has cycle" << endl;
            return true;
        }
    }
    
    cout << "No has not cycle" << endl;
    
    return false;
}

int colors[nmax], parent[nmax];

bool bfsc(int source) {
    queue<int > Q;
    memset(colors, -1, sizeof colors);
    memset(parent, -1, sizeof parent);
    Q.push(source);
    colors[source] = 0;
    bool bipart = true;

    while(Q.size()) {
        int u = Q.front(); Q.pop();
    
        for (auto v : joint[u]) {
            if (colors[v] != -1) {
                if (parent[u] == v) {
                    continue;
                }      
                if (colors[v] == colors[u]) {
                    bipart = false;    
                }
            } else {
               colors[v] = colors[u] ^ 1;
               parent[v] = u;
               Q.push(v);
            }
        }

    }
    
    return bipart;
}


bool is_bipartite() {
    
    bool res = bfsc(1);
    if(res) cout << "this graph is bipartite." << endl;
    else cout << "this graph is non bipartite." << endl;

    return res;

}


signed main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    while(m -- ) {
        int u, v;
        cin >> u >> v;
        joint[u].push_back(v);
        joint[v].push_back(u);
    }

    
    
    get_all_components();

    get_level_elements();

    is_bipartite();


    return 0;
}
