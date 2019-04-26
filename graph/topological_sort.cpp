// DAG

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define notused 0
#define processing 1
#define processed 2 


const int nmax = (int)1e5 + 10;
int n, m;
vector<int > joint[nmax];
int indeg[nmax];
int status[nmax];
vector<int > topo;
bool has_cycle = false;

void dfs(int from) {
    status[from] = processing;
    for (auto to : joint[from]) {
       if (status[to] == processing) {
            has_cycle = true;   
       }   

       if(status[to] == notused) {
        dfs(to);
       }
                      
    }
    status[from] = processed;
    topo.push_back(from);
}


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    while( m -- ) {
        int from, to;
        cin >> from >> to;
        joint[from].push_back(to);
        indeg[to] ++;
    }


    vector<int > roots;
    for (int i = 1; i <= n; i ++) {
        if ( indeg[i] == 0 ) {
            roots.push_back(i);   
        }
    }

    int father = 0;
    for (auto root : roots) {
        joint[father].push_back(root);    
    }

    has_cycle = false;
    memset(status, notused, sizeof status);
    dfs(father);

    assert(has_cycle == false);

    reverse(topo.begin(), topo.end());
    cout << endl;
    for (auto x : topo) {
        cout << x << " "; 
    } cout << endl;




    return 0;
}