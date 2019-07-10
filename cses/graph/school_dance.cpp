#include <bits/stdc++.h>
using namespace std;
#define emax 5003
#define nmax 5002

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
   // edges[cnt].init(to, from, cap, lastpos[to]); lastpos[to] = cnt ++; 
}

int source, tank;
int parent[nmax], vis[nmax];


bool bfs() {
    queue<int > Q;
    memset(parent, -1, sizeof parent);
    memset(vis, 0, sizeof vis);
    
    Q.push(source);
    vis[source] = true;
    
    while (Q.size()) {
        int from = Q.front(); Q.pop();
        if (from == tank) break;
        for (int i = lastpos[from]; i != -1; i = edges[i].pre) {
            int to = edges[i].to;
            int cap = edges[i].cap;
            if (vis[to]) continue;
            if (cap <= 0) continue;
            vis[to] = true;
            Q.push(to);
            parent[to] = i;    
        }

    }
    return vis[tank];         
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
            if (edges[j].cap <= 0) continue;
            int flowed = flowing(edges[j].from, edges[j].cap);
            edges[j].cap -= flowed;
            edges[i].cap += flowed;
            max_flow += flowed;
        }      
    }

    return max_flow;
}


signed main() {

    int n, m, k;
    cin >> n >> m >> k;
    
    memset(lastpos , -1 ,sizeof lastpos);
    source = 0;
    tank = n + m + 1;
    
    for (int boy = 1; boy <= n; boy ++) {
        add_edge(source, boy, 1);
        add_edge(boy, source, 0);
    }

    for (int girl = 1; girl <= m; girl ++) {
        add_edge(n + girl, tank, 1);
        add_edge(tank, n + girl, 0);
    }

    while (k -- ) {
        int boy, girl;
        cin >> boy >> girl;
        add_edge(boy, n + girl, 1);
        add_edge(n + girl, boy, 0);                
    }
    
    int res = get_max_flow();

    cout << res << endl;
    
    for (int i = 1; i < cnt; i ++) {
        int from = edges[i].from;
        int to = edges[i].to;
        int cap = edges[i].cap;
        if (from > to) continue;
        if (from == source) continue;
        if (to == tank) continue;

        if (cap != 0) continue;
        cout << from << " " << to - n << endl;   
        
    }



    return 0;
}