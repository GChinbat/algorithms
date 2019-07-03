#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define nmax 1010
#define Pair pair<int, int >
#define xx first
#define yy second
#define inf INT_MAX



int n, m;
string s[nmax];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
string dr = "UDLR";


vector<Pair> Ms;
Pair A;
vector<vector<int>> distM;




void bfsM() {
    
    queue<Pair> Q;

    distM.assign(n + 1, vector<int > (m + 1, inf));

    for (auto p : Ms) {
        Q.push(p);
        distM[p.xx][p.yy] = 0;                
    }

    while (Q.size() ) {
        Pair p = Q.front(); Q.pop();
        for (int i = 0; i < 4; i ++) {
            int x = p.xx + dx[i];
            int y = p.yy + dy[i];
            if ( x < 0 || y < 0 || x >= n || y >= m) continue;
            if (distM[x][y] != inf) continue;
            if (s[x][y] == '#') continue;
            if (s[x][y] == 'B') continue;
            distM[x][y] = distM[p.xx][p.yy] + 1;
            Q.push(mp(x, y));
        }    
    }       
}

vector<vector<int > > dist;
vector<vector<Pair> > parent;


Pair bfsA() {
    queue<Pair > Q;

    dist.assign(n + 1, vector<int > (m + 1, inf));
    parent.assign(n + 1, vector<Pair > (m + 1, mp(-1, -1)));
    
    Q.push(A);
    dist[A.xx][A.yy] = 0;
    
    Pair gate = mp(-1, -1);

    while (Q.size()) {
        Pair p = Q.front(); Q.pop();
        if (s[p.xx][p.yy] == 'B') {
            gate = p;
            break;
        }
        for (int i = 0; i < 4; i ++) {
            int x = p.xx + dx[i];
            int y = p.yy + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (dist[x][y] != inf) continue;
            if (s[x][y] == '#') continue;
            int tmp_dist = dist[p.xx][p.yy] + 1;
            if (tmp_dist > distM[p.xx][p.yy]) continue;
            Q.push(mp(x, y));
            dist[x][y] = tmp_dist;
            parent[x][y] = p;    
        } 
    }
    return gate;
}

char get_dir(Pair p) {

    for (int i = 0; i < 4; i ++) {
        if (p.xx == dx[i] && p.yy == dy[i]) {
            return dr[i];
        }
    } 
    return '#';
}

string get_path(Pair t) {
    int x = t.xx;
    int y = t.yy;
    vector<Pair > path;
    while (x != -1 && y != -1) {
        path.pb(mp(x, y));
        Pair p = parent[x][y];
        x = p.xx;
        y = p.yy;
    }

    reverse(path.begin(), path.end());

    string res = "";
    for (int i = 1; i < path.size() - 1; i ++) {
        res += get_dir(mp(path[i].xx - path[i - 1].xx, path[i].yy - path[i - 1].yy));           
    }

    
    return res;
}


signed main() {

    cin >> n >> m;

    string tmp = "";
    for (int i = 0; i <= m + 1; i++) {
        tmp += 'B';
    }

    s[0] = tmp;
    s[n + 1] = tmp;

    for (int i = 1; i <= n; i ++) {
        cin >> tmp;
        s[i] = "B";
        s[i] += tmp;
        s[i] += "B";
    }

    n +=2;
    m +=2;

    for (int i  =0; i < n; i ++) {
        for (int j = 0; j <m ; j++) {
            if (s[i][j] == 'A') {
                A = mp(i, j);
            }
            if (s[i][j] == 'M') {
                Ms.pb(mp(i, j));
            }
        }
    }

    bfsM();
    
    Pair res = bfsA();

    if (res.xx == -1 || res.yy == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << dist[res.xx][res.yy] - 1 << endl;  
        string ans = get_path(res);
        cout << ans << endl;
    }
       
    return 0;
}