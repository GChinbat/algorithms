#include <bits/stdc++.h>
using namespace std;

#define pb push_back

#define nmax (1 << 16)

int n;

map<string, int> has;


vector<int > graph[nmax], path;


void dfs(int u) {
    
    while(graph[u].size()) {
        int v = graph[u].back();
        graph[u].pop_back();
        dfs(v);
    }
    
    path.pb(u);
}



signed main() {

       
    cin >> n;

    if (n == 1) {
        cout << "01" << endl;
        return 0;
    }    

    int m = n - 1;
    vector<string > s;
    s.pb("");
    for (int i = 0; i < (1 << m); i ++) {
        string ss = "";
        for (int j = 0; j < m;j ++) {
            if ((i & (1 << j)) != 0) {
                ss += '1';       
            } else {
                ss += '0';
            }
        }
        s.pb(ss); 
        has[ss] = i + 1;
    }

  
    for (int i = 1; i <= (1 << m); i ++) {
        string from = s[i];
        string to1, to2;

        if (s[i].size() > 1) {
            to1 = s[i].substr(1, from.size()) + "1";
            to2 = s[i].substr(1, from.size()) + "0";
        } else {
            to1 = "1";
            to2 = "0"; 
        }
        graph[has[from]].pb(has[to1]);
        graph[has[from]].pb(has[to2]);                             
    }
    
    dfs(1);

    string ans = "";
    ans += s[1];
    
    reverse(path.begin(), path.end());
    for (int i = 1; i < path.size(); i ++) {
        ans += s[path[i]][m - 1];    
    } cout << ans << endl;


    return 0;
}