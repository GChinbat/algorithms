#include <bits/stdc++.h>
using namespace std;

int a[3] = {1, 2, 3};

vector<int > b;

void dfs(int id) {
    
    if ( id == 3) {
        for (int i = 0; i < b.size(); i ++) {
            cout << b[i] << " ";
        } cout << endl;
        return ;
    }
    
    b.push_back(a[id]);
    dfs(id + 1);
    b.pop_back();
    dfs(id + 1);
}


signed main() {
    
    dfs(0);
    
    
    return 0;
}