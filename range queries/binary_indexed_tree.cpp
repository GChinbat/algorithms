#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
#define mod 1000000007

int n;
    
const int nmax = (int)1e5 + 10;
int tree[nmax], a[nmax];


int p(int k) {
    return k & -k;
}

int build(int beg, int fin) {
     
    int s = a[fin];
    fin -= 1;
    while (beg <= fin) {
        s += tree[fin];
        fin -= (fin & (-fin));
    }
    return s;
}

int sum(int fin) {
    int s = 0;
    while (fin > 0) {
        s += tree[fin];
        fin -= (fin & -fin);    
    }
    return s;
}


int get_sum(int beg, int fin) {
    return sum(fin) - sum(beg - 1);              
}

int increase_val(int pos, int inc) {
    a[pos] += inc;
    while(pos <= n) {
        tree[pos] += inc;
        pos += (pos & -pos);
    }    
}
                       

signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);


    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++) {
        tree[i] = build(i - p(i) + 1, i);
        cout << tree[i] << " ";
    }
    cout << endl;

    
    int q;
    cin >> q;
    while ( q --) {
        
        int flag, beg, fin;
        cin >> flag >> beg >> fin;
        
        if (flag) { 
            int res = get_sum(beg, fin);
            cout << res << endl;
        } else {
            increase_val(beg, fin);
            for (int i = 1; i <= n; i ++) {
                cout << tree[i] << " ";
            }
            cout << endl;
        } 
    
    }

    
    return 0;
}