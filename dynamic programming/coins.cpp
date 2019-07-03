#include <bits/stdc++.h>
using namespace std;


int a[3] = {1, 2, 3};
vector<int > b;
bool used[3] = {0};

void dfs() {
    
    if (b.size() == 3) {
        for (int i = 0; i < b.size(); i ++) {
            cout << b[i] << " ";
        } cout << endl;
        return ;
    }
    
    for (int i = 0; i < 3; i ++) {
        if ( used[i] == 0) {
            used[i] = true;
            b.push_back(a[i]);
            dfs();
            used[i] = false;
            b.pop_back();
        }
    }
    
}

signed main() {
     
    
    dfs();
    
    return 0;
}