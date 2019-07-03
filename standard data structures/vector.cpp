#include <bits/stdc++.h>
using namespace std;
#define int long long

bool comp(int x, int y) {
    return x > y;
}

void print_datas(vector<int > a) {
    
    cout << "print ::  " << endl;
    
    for (int i = 0; i < a.size(); i ++) {
        cout << a[i] << " "; 
    }
    cout << endl;
    
    for (int i = 0; i < a.size(); i ++) {
        cout << a.at(i) << " "; 
    }  
    cout << endl;
  
    for (auto x : a) {
        cout << x << " ";
    }
    cout << endl;
    
}

signed main() {

    vector<int > a(5);
    vector<int > b(5, 2);
    vector<int > c;
    vector<int > d = {1, 2, 3, 4, 100, 5};
    
    print_datas(a);
    print_datas(b);
    print_datas(d);
    sort(d.begin(), d.end());
    print_datas(d);
    reverse(d.begin(), d.end());
    print_datas(d);
    
    for (auto x : d) {
        c.push_back(x);
    }
    
    while(!c.empty()) {
        cout << c.back() << endl;
        c.pop_back();
    }
    
    sort(d.begin(), d.end());
    
    sort(d.begin(), d.end(), comp);
    cout << endl;
    for (auto x : d) {
        cout << x << " ";
    }
    cout << endl;
  
    return 0;
}