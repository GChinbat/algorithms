#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define inf (int)1e18 + 9
const int nmax = (int)1e6 + 10;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;



signed main() {

    indexed_set iset;
    iset.insert(12);
    iset.insert(24);
    iset.insert(12);
    iset.insert(34);
    iset.insert(45);

    for (auto x : iset) {
        cout << iset.order_of_key(x) << ": ";
        cout << x << endl;
    }


    cout << endl;
    for (int i = 0; i < iset.size(); i ++) {
        cout << i << ": ";
        auto x =  iset.find_by_order(i);
        cout << *x << endl; 
    }

    iset.erase(iset.find_by_order(2));

    cout << endl;
    for (auto x : iset) {
        cout << x << " ";
    }




    return 0;
}