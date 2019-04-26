#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007

int n, m;
const int nmax = 505;
int dist[nmax][nmax];
bool con[nmax][nmax];
int path[nmax][nmax];


void floyd_warshal() {

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (!con[i][j]) {
               if (i == j) dist[i][j] = dist[j][i] = 0;
               else dist[i][j] = dist[j][i] = inf; 
            }            
        }
    }

    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
           
}


void floyed_warshal_with_path() {
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (!con[i][j]) {
                if ( i == j) dist[i][j] = 0;
                else dist[i][j] = inf;    
            }
        }
    }

    memset(path, -1, sizeof path);

    for (int i = 1; i<= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cout << dist[i][j] << " ";
        }                            
        cout << endl;
    }
    cout <<endl;


    // let p[][] = k
    for (int k = 1; k <= n; k ++) {
        for(int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                int tmp = dist[i][k] + dist[k][j];
                if ( tmp < dist[i][j]) {
                    dist[i][j] = tmp;
                    path[i][j] = k;
                }
            }
        }
    }

    cout << endl;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
  


    int from = 4; 
    int to = 5;

    vector<int > res;
    res.push_back(to);
    while(true) {
        int last = path[from][to];
        if (last == -1) break;
        res.push_back(last);
        to = last;
    }
    res.push_back(from);

    reverse(res.begin(), res.end());
    cout << endl;
    for (auto p : res) {
        cout << p << ", ";
    }
    cout << endl;

}




signed main() {
    
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
 
    cin >> n >> m;
    while( m -- ) {
        int from, to, w;          
        cin >> from >> to >> w;
        cout << from << " " << to << " " << w << endl;
        
        //input is referring nodes with the numbers from 0,  but my algorithm works with  numbers above the zero
        from ++; to ++;
                                  
        con[from][to] = true;
       // con[to][from] = true;
        dist[from][to] = w;
       // dist[to][from] = w;
    }
    
    floyed_warshal_with_path();

    return 0;
}
