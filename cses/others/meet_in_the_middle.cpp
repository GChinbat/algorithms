#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair  
#define mod 10000000007


int n, n1, n2;
long long x, t1[21], t2[21];


map<long long, int > cache1;
long long memo1[(1 << 20) + 1];

int log2(int x) 
{ 
    int res = 0; 
    while (x >>= 1) 
        res++; 
    return res; 
} 


signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    n1 = n / 2;
    n2 = n - n1;

    for (int i = 0; i < n1 ; i ++) {
        cin >> t1[i];
    }

    for (int i = 0; i < n2; i ++) {
        cin >> t2[i];
    }
    
    memo1[0] = 0;
    int last_i = 0;
    
    int ans = 0;

    for (int bitmask = 0; bitmask < (1 << n1); bitmask ++) {
        long long sum = 0;
        for (int i = last_i; i <= last_i + 1; i ++) {  
          if ( (bitmask & (1 << i)) ) {
                sum += t1[i];
                int tmp = bitmask & (~(1 << i));
                sum += memo1[tmp];
                last_i = i;
                break;
            }    
        }
        memo1[bitmask] = sum;
        if (sum <= x) cache1[sum] ++;                 
    }

    
    memset(memo1, 0, sizeof memo1);

    memo1[0] = 0;
    last_i = 0;
    for (int bitmask = 0; bitmask < ( 1 << n2); bitmask ++) {
        long long sum = 0;
        
        for (int i = last_i; i <= last_i + 1; i ++) { 
            if ( bitmask & ( 1 << i ) ) {
                sum += t2[i];
                int tmp = bitmask & (~(1 << i));
                sum += memo1[tmp];
                last_i = i;
                break;
            }
        }
        memo1[bitmask] = sum;
        if (sum <= x) {
            long long target = x - sum;  
            ans += cache1[target];
        }
    }
                     
    cout << ans << endl;
    
    return 0;
}