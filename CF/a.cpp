#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+10

string s;

#define D 0
#define U 1
#define L 2
#define R 3

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n = 7;
int ans = 0;
int visited[10][10];
string mm = "DULR";


vector<int > path;


void dfs(int x, int y, int id) {
    
    
    if (id == 48) {
        if (x == 6 && y == 0) {
            ans ++;
            string rr = "\"";
            for (auto& c : path) {
                rr += c;
            }
            rr += "\"";
            rr += ",";
            cout <<  rr << endl;

            return ;
        }
        return ;
    }    

    
    for (int i = 0; i < 4; i ++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
        if (visited[xx][yy]) continue;

        if (s[id] == '?') {
            visited[xx][yy] = true;
            path.pb(mm[i]);
            dfs(xx, yy, id + 1);
            path.pop_back();
            visited[xx][yy] = false;
            continue;
        } else {
            if (s[id] == 'U' && i == U) {
                visited[xx][yy] = true;
                path.pb(mm[i]);
                dfs(xx, yy, id + 1);
                path.pop_back();
                visited[xx][yy] = false;
                break;
            }
            if (s[id] == 'D' && i == D) {
                visited[xx][yy] = true;
                path.pb(mm[i]);
                dfs(xx, yy, id + 1);
                path.pop_back();
                visited[xx][yy] = false;
                break;
            }
            if (s[id] == 'L' && i == L) {
                visited[xx][yy] = true;
                path.pb(mm[i]);
                dfs(xx, yy, id + 1);
                path.pop_back();
                visited[xx][yy] = false;
                break;
            }
            if (s[id] == 'R' && i == R) {
                visited[xx][yy] = true;
                path.pb(mm[i]);
                dfs(xx, yy, id + 1);
                path.pop_back();
                visited[xx][yy] = false;
                break;
            }
        } 
    }
    
    return ;
}


signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

        cin >> s;

    memset(visited, 0, sizeof visited);
    visited[0][0] = true;
    dfs(0, 0, 0);

    cout << ans << endl;


    

    return 0;
}