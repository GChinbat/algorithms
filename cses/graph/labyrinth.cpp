#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define Pair pair<int, int >
#define xx first
#define yy second
#define inf INT_MAX


int n, m;

string grid[1100];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
string dr = "LRUD";

int sx, sy, tx, ty;

vector<vector<Pair>> parent;        
vector<vector<int >> dist;


bool solve() {
    queue<Pair> Q;
    parent.assign(n + 1, vector<Pair>(m + 1, mp(-1, -1)));
    dist.assign(n + 1, vector<int > (m + 1, inf));


    Q.push(mp(sx, sy));
    dist[sx][sy] = 0;
    
    while ( Q.size() ) {
        Pair p = Q.front(); Q.pop();
        if (p.xx == tx && p.yy == ty) {
            break;
        }
        for (int i = 0; i < 4; i ++) {
            int x = p.xx + dx[i];
            int y = p.yy + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (dist[x][y] != inf) continue;
            if (grid[x][y] == '#') continue;
            dist[x][y] = dist[p.xx][p.yy] + 1;
            parent[x][y] = p;
            Q.push(mp(x, y));
        }     
    }       

    return (dist[tx][ty] != inf);
}

char get_dir(Pair p) {
    for (int i = 0; i < 4; i ++) {
        if (p.xx == dx[i] && p.yy == dy[i]) {
            return dr[i];
        }
    }
}


string get_path() {
    int x = tx;
    int y = ty;
    vector<Pair > path;
    while (x != -1 && y != -1) {
        path.pb(mp(x, y));
        Pair pa = parent[x][y];
        x = pa.xx;
        y = pa.yy;   
    }

    reverse(path.begin(), path.end());

    string ans = "";
    for (int i = 1; i < path.size(); i ++) {
        ans += get_dir(mp(path[i].xx - path[i - 1].xx, path[i].yy - path[i - 1].yy));    
    }
    return ans;
}


signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
            
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        cin >> grid[i];
        for (int j = 0; j < grid[i].size(); j ++) {
            if (grid[i][j] == 'A') {
                sx = i; sy = j;
            }
            if (grid[i][j] == 'B') {
                tx = i; ty = j;
            }
        }
    }

    bool ok = solve();

    if (!ok) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        cout << dist[tx][ty] << endl;
        string ans = get_path();
        cout << ans << endl;
    }



    return 0;
}