#include <bits/stdc++.h>
using namespace std;


#define int long long
#define nmax 505
#define emax 3005


int n, m;


struct Edge {
    int to, from, cap, pre;
    void init(int from, int to, int cap, int pre) {
        this->from = from;
        this->to = to; 
        this->cap = cap;
        this->pre = pre;
    }
} edges[emax];


int curpos[nmax], ecnt = 0;


void add_edge(int from, int to, int cap) {
    edges[ecnt].init(from, to, cap, curpos[from]); curpos[from] = ecnt ++;
    edges[ecnt].init(to, from, cap, curpos[to]); curpos[to] = ecnt ++;
}


int source, tank;
vector<int > parent_pos;
vector<bool > visited;


bool bfs() {

    queue<int > Q;
    parent_pos.assign(n + 1, -1);
    visited.assign(n + 1, false);
    Q.push(source);
    visited[source] = true;

    while (Q.size()) {
        int from = Q.front(); Q.pop();
        if (from == tank) break;
        for (int i = curpos[from]; i != -1; i = edges[i].pre) {
                
            int to = edges[i].to;
            int cap = edges[i].cap;

            if (visited[to]) continue;
            if (cap <= 0) continue;

            Q.push(to);
            visited[to] = true;
            parent_pos[to] = i;
        }
        
    }
    
    return visited[tank];
}


int flowing(int to, int flow) {   
    if (to == source) return flow;
    int p_pos = parent_pos[to];
    if (p_pos == -1) {
        return 0;
    }
    int from = edges[p_pos].from;
    int cap = edges[p_pos].cap;
    int flowed = flowing(from, min(flow, cap));
    edges[p_pos].cap -= flowed;
    edges[p_pos ^ 1].cap += flowed;
    return flowed;
}


int get_max_flow() {
    int max_flow = 0;
    while (bfs()) {
        for (int i = curpos[tank]; i != -1; i = edges[i].pre) {
            int j = i ^ 1;
            int from = edges[j].from;
            int cap = edges[j].cap;
            if (cap <= 0) continue;
            
            int flowed = flowing(from, cap);
            edges[j].cap -= flowed;
            edges[i].cap += flowed;      
            max_flow += flowed;
        }
         
    }
    return max_flow;
}


signed main() {

    cin >> n >> m;
    memset(curpos, -1, sizeof curpos);    
    source = 1; tank = n;
    while (m -- ) {
        int from, to;
        cin >> from >> to;
        add_edge(from, to, 1);
    }    
    
    int ans = get_max_flow();
    cout << ans << endl;

    for (int i = 0; i < ecnt; i ++) {
        if (edges[i].cap == 0) {
            if (visited[edges[i].from] && !visited[edges[i].to]) {
                cout << edges[i].from << " " << edges[i].to << endl;    
            }
        }
    }
    

    return 0;
}