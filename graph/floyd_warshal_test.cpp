#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e9+7

int P, R, BH, OF, YH, M;
int n;

int dist[110][110];
bool con[110][110];
int edge[110][110];
int before_end[110][110];


vector < int > get_path(int beg, int fin) {

    for (int i =  1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            
            if (con[i][j]) {
                dist[i][j] = dist[j][i] = edge[i][j];
            } else {
                dist[i][j] = dist[j][i] = inf;
            }
                     
        }
    }

    memset(before_end, -1, sizeof before_end);

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if ( dist[i][j] != inf)
                before_end[i][j] = i;
        }
    }

    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                int tmp = dist[i][k] + dist[k][j];
                if ( dist[i][j] > tmp) {
                    dist[i][j] = tmp;
                    before_end[i][j] = before_end[k][j];
                }                  
            }
        }
    }

    vector <int > path;
    path.push_back(fin);
    //cout << "orseon " << endl;
    while(true) {
       if ( beg == fin) break;
       int res = before_end[beg][fin];
       if (res == -1) break;
       path.push_back(res);
       fin = res; 
    }
    //cout << "garsan " << endl;
    
    reverse(path.begin(), path.end());
    return path;
}


void delete_path(vector<int > path) {
    
    for (int i = 1; i < path.size(); i ++) {
        con[path[i - 1]][path[i]] = con[path[i]][path[i - 1]] = false;   
    }
         
}

void delete_all(vector<int > all) {

    for (auto p : all) {
        for (int i = 1; i <= n; i ++) {
            con[p][i] = con[i][p] = false;
        }
    }
}


signed main() {

    while(cin >> P) {
        cin >> R >> BH >> OF >> YH >> M;
        n = P;
        memset(con, false, sizeof con);
        memset(edge, 0, sizeof edge);
        for (int i = 0; i < R; i ++) {
            int to, from, w;
            cin >> to >> from >> w;
            con[to][from] = con[from][to] = true;
            edge[to][from] = edge[from][to] = w;
            con[to][to] = con[from][from] = true;
        }

        vector<int > all;
        vector<int > path = get_path(BH, OF);
        int shortest_dist = dist[BH][OF];
        
        if (shortest_dist == inf) {
            path.push_back(OF);
        }

        for (auto p : path) {
            all.push_back(p);
        }
        
        delete_path(path);
        // cout << shortest_dist << " -> ";
        while(true) {
            if ( BH == OF) break;
            if ( shortest_dist == inf) break;
            path = get_path(BH, OF);
           // cout << shortest_dist << " -> ";
            if (shortest_dist < dist[BH][OF]) {
                break;
            }
            for (auto p : path) {
                all.push_back(p);
            }
            delete_path(path);
        }
        // cout << endl;

        delete_all(all);

        get_path(YH, M);
    
        if (dist[YH][M] == inf) puts("MISSION IMPOSSIBLE."); 
        else cout << dist[YH][M] << endl;
    }

    return 0;
}