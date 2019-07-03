#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18 + 9
const int nmax = (int)1e6 + 10;



signed main() {
    
    unordered_map<string, int > umap;

    umap["chinbat"] = 2;
    umap["dorj"] = 14;
    umap["bataa"] = 345;

    cout << umap["dorj"] << endl;

    cout << umap.count("dulam") << endl;
    cout << umap.count("chinbat") << endl;

    cout << umap["dulam"] << endl;
    cout << umap.count("dulam") << endl;

    for (auto p : umap) {
        cout << p.first << " " << p.second << endl;
    }


    return 0;
}