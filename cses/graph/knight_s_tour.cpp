#include <bits/stdc++.h>
using namespace std;


int dx[8] = {2, 2, 1, -1, -2, -2, 1, -1};
int dy[8] = {1, -1, 2, 2, 1, -1, -2, -2};

int n = 8, m = 8;

int ans[8][8] = {0};

int count_movement(int x, int y) {
    
    int cnt = 0;
    for (int i = 0; i < 8; i ++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
            continue;
        }
        if (ans[xx][yy] != 0) continue;

        cnt ++;

    }
    return cnt;

} 


void solve(int x, int y, int id) {
    ans[x][y] = id;

    int finx = 0, finy = 0;
    int mx_cnt = 10;
    for (int i = 0; i < 8; i ++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if ( xx < 0 || yy < 0 || xx >= n || yy >= m ) {
            continue;    
        }
        if (ans[xx][yy] != 0) continue;

        int tmp_cnt = count_movement(xx, yy);
        if (tmp_cnt < mx_cnt) {
            mx_cnt = tmp_cnt;
            finx = xx; 
            finy = yy;
        }
    }
    if (mx_cnt != 10) {
        solve(finx, finy, id + 1);
    }
}



signed main() {
    
    int x, y;
    cin >> x >> y;
    x --; y --;

    swap(x, y);
    solve(x, y, 1);

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    

    



    return 0;
}