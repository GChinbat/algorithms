#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7

const int nmax = (int) 1e6 + 10;

signed main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    
    map<string, int > mmap;
    
    mmap["chinbat"] = 1;
    mmap["john"] = 4;
    mmap["muhammed"] = 2000;
    
    cout << mmap["john"] << endl;
        
    cout << mmap.count("muhamed") << endl;
    cout << mmap.count("dorj") << endl;
    cout << mmap["dorj"] << endl;
    
    cout << mmap.count("dorj") << endl;
    
    for (auto p : mmap) {
        cout << p.first << " " << p.second << endl;
    }
    
    cout << mmap.size() << endl;

    return 0;
}