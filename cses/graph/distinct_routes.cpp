#include <bits/stdc++.h>
using namespace std;
#define emax 50005
#define nmax 5005

struct Edge {
    int from, to, cap, pre;
    void init(int from, int to, int cap, int pre) {
        this -> from = from;
        this -> to = to;
        this -> cap = cap;
        this -> pre = pre;
    }
} edges[emax];

int lastpos[nmax], cnt = 0;

void add_edge(int from, int to, int cap) {
    edges[cnt].init(from, to, cap, lastpos[from]); lastpos[from] = cnt ++;
    edges[cnt].init(to, from, 0, lastpos[to]); lastpos[to] = cnt ++;
}

int source, tank;
bool visited[nmax];
int parent[nmax];


bool bfs() {
    queue<int > Q;
    memset(parent, -1, sizeof parent);
    memset(visited, 0, sizeof visited);

    Q.push(source);
    visited[source] = true;

    while (Q.size()) {
        int from = Q.front(); Q.pop();
        if (from == tank) break;
        for (int i = lastpos[from]; i != -1; i = edges[i].pre) {
            int to = edges[i].to;
            int cap = edges[i].cap;
            if (visited[to]) continue;
            if (cap <= 0) continue;
            Q.push(to);
            visited[to] = true;
            parent[to] = i;
        }
    }

    return visited[tank];
}


int flowing(int to, int flow) {
    if (to == source) return flow;    
    int i = parent[to];
    if (i == -1) return 0;
    int from = edges[i].from;
    int cap = edges[i].cap;
    int flowed = flowing(from, min(cap, flow));
    edges[i].cap -= flowed;
    edges[i ^ 1].cap += flowed;
    return flowed;
}


int get_max_flow() {
    int max_flow = 0;
    while (bfs()) {
        for (int i = lastpos[tank]; i != -1; i = edges[i].pre) {
            int j = i ^ 1;
            int from = edges[j].from;
            int cap = edges[j].cap;
            int flowed = flowing(from, cap);
            edges[j].cap -= flowed;
            edges[i].cap += flowed;
            max_flow += flowed;
        }
    }
    return max_flow;
}


bool bfs1() {
    queue<int > Q;
    memset(parent, -1, sizeof parent);
    memset(visited, 0, sizeof visited);
    Q.push(source);
    visited[source] = true;
    while (Q.size()) {
        int from = Q.front(); Q.pop();
        for (int i = lastpos[from]; i != -1; i = edges[i].pre) {
            int to = edges[i].to;
            int cap = edges[i].cap;
            if (visited[to]) continue;
            if (cap == 0) {
                Q.push(to);
                visited[to] = true;
                parent[to] = i;
            }
        }
    }
    return visited[tank];
}


vector<int > path;

void get_path(int to) {
    if (to == source) {
        return ;
    }
    int i = parent[to];
    assert(i != -1);
    int from = edges[i].from;
    path.push_back(from);    
    get_path(from);
}


signed main() {
    
    //freopen("in", "r", stdin);
    
    memset(lastpos, -1, sizeof lastpos);
      
    int n, m;
    cin >> n >> m;
    while ( m -- ) {
        int from, to;
        cin >> from >> to;
        add_edge(from, to, 1);
    }
    source = 1;
    tank = n;

    int ans = get_max_flow();
    cout << ans << endl;
    
    bool res = bfs1();
    
    for (int i = lastpos[tank]; i != -1; i = edges[i].pre) {
        int j = i ^ 1;
        int from = edges[j].from;
        int cap = edges[j].cap;
        if (cap != 0) continue;
        path.push_back(tank);
        path.push_back(from);
        get_path(from);
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (auto node : path) {
            cout << node << " ";
        }
        cout << endl;
        path.clear();  
    }
    

    return 0;
}