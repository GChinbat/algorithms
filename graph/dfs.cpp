#include <bits/stdc++.h>
using namespace std ;
#define int long long
const int nmax = (int)1e5 + 10;

int n, m;
vector<int > joint[nmax];
bool visited[nmax];
vector<int > nodes;
        

void dfs(int u) {
    visited[u] = true;
    
    nodes.push_back(u);

    for (auto v : joint[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
}

vector<vector<int > > detect_all_components() {
    
    memset(visited, 0, sizeof visited);
    vector<vector<int > > components;
    for (int u = 1; u <= n; u ++) {
        nodes.clear();
        if (visited[u] == false) {
            dfs(u);   
        }
        components.push_back(nodes);    
    }

    cout << "number of components :: " << components.size() << endl;
    for (int i = 1; i < components.size(); i ++) {
        nodes.clear();
        nodes = components.at(i);
        cout << "component #" << i << " :: ";
        for (auto u : nodes) {
            cout << u << ", ";
        } cout << endl;
    }

    return components;
}

int parent[nmax];
bool hascycle;
int cyclenode;


void dfs1(int u) {
    visited[u] = true;
    if (hascycle) return ;
    for (auto v : joint[u]) {
        if ( visited[u]) {
            if ( parent[v] != u) {
                hascycle = true;        
                cyclenode = v;
            }
        }
        parent[v] = u;
        dfs1(v);    
    }
}


void detect_cycle(int root) {

    memset(visited, 0, sizeof visited);
    memset(parent, -1, sizeof parent); 

    hascycle = false;
    cyclenode = -1;
    dfs1(root);

    memset(visited, 0, sizeof visited);
    vector<int > cycles;
    if (hascycle) {
        while (true) {
            if ( visited[cyclenode]) break;
            visited[cyclenode] = true;
            cycles.push_back(cyclenode);
            cyclenode = parent[cyclenode];       
        }
    }

    cout << endl;
    for (auto u : cycles) {
        cout << u << ", ";
    }
    cout << endl;

}


bool has_cycle() {
    
    vector<vector<int > > components = detect_all_components();

    hascycle = false;
    for (auto component : components) {
        assert(component.size() > 0);
        int degree = 0;
        bool iscyclic = false;
        for (auto u : component) {
            degree += joint[u].size();
        }
        int edgeNo = degree / 2;
        if ( component.size() != edgeNo - 1) {
           hascycle = true;
           iscyclic = true;
           detect_cycle(component.back()); 
        }
    }

    return hascycle;
}


int colors[nmax];
bool is_bipart = true;


void dfsc(int u) {
    visited[u] = true;
    for (auto v : joint[u]) {
        if (visited[v]) {
            if ( colors[u] == colors[v]) {
                is_bipart = false;    
            }
            continue;
        }
        colors[v] = colors[u] ^ 1;
        dfsc(v); 
    }
}



bool is_bipartite() {

    memset(colors, 0, sizeof colors);    
    colors[1] = 1;
    is_bipart = true;

    dfsc(1);
    if (is_bipart) {
        cout << "Yes, this graph is bipartite" << endl;
    } else {
        cout << "No, this graph is not bipartite" << endl;
    }

    return is_bipart;

}


signed main() {
    
    
    cin >> n >> m;
    while (m -- ) {
        int u, v;
        cin >> u >> v;        
        joint[u].push_back(v);
    }


    return 0;
}


// detecting connected components
// detecting cycle  
// detecting has cycle
// is bipartite
 
