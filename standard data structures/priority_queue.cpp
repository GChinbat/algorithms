#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18 + 9
#define pb push_back
#define mp make_pair

const int nmax = (int)1e6 + 10;

struct Point {
    int x, y, z;
    Point(int x, int y, int z) : x(x), y(y), z(z) {
        
    }
};

struct Comp {
   // bool operator() (const int& a, const int& b) const{
  //      return a > b;
   // }

    bool operator() (const Point& a, const Point& b) {
        return !order(a, b);
    }

    bool order (const Point& a, const Point& b) {
         if ( a.x > b.x ) return true;
        if ( a.x == b.x) {
            if ( a.y > b.y) return true;
            if (a.y == b.y) {
                return a.z > b.z;
            }
        }
        return false;
    }


} ;


struct Comp1 {

    bool operator() (const int& a, const int& b) const{
      return a > b;
    }
}    ;





signed main() {
    
    priority_queue<int > pq;
    
    pq.push(34);
    pq.push(12);
    pq.push(34);
    pq.push(45);
    pq.push(1000);

    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    cout << endl;

    priority_queue<int, vector<int >, Comp1> rpq;
    
    rpq.push(34);
    rpq.push(12);
    rpq.push(34);
    rpq.push(45);
    rpq.push(1000);

    while(!rpq.empty()) {
        cout << rpq.top() << endl;
        rpq.pop();
    }

    typedef pair<int, pair<int, int> > ppp;


    priority_queue<ppp, vector<ppp >, greater<ppp> > haha;

    haha.push(mp(12, mp(22, 56)));
    haha.push(mp(10, mp(2, 33)));
    haha.push(mp(2, mp(41, 2)));
    haha.push(mp(2, mp(42, 2)));
    haha.push(mp(2, mp(43, 2)));
    haha.push(mp(2, mp(41, 5)));
    haha.push(mp(2, mp(41, 6)));
    haha.push(mp(2, mp(41, 7)));
    haha.push(mp(23, mp(51, 3)));
    haha.push(mp(1000, mp(1, 23)));

    cout << endl;
    while(!haha.empty()) {
        ppp p = haha.top();
        cout << p.first << " " << p.second.first << " " << p.second.second << endl;
        haha.pop();
    }
    
    cout << endl;

    priority_queue<Point, vector<Point>, Comp > tursh;

    tursh.push(Point(12, 22, 56));
    tursh.push(Point(10, 2, 33));
    tursh.push(Point(2, 41, 2));
    tursh.push(Point(2, 42, 2));
    tursh.push(Point(2, 43, 2));
    tursh.push(Point(2, 41, 5));
    tursh.push(Point(2, 41, 6));
    tursh.push(Point(2, 41, 7));
    tursh.push(Point(23, 51, 3));
  
    while(tursh.size()) {
        Point p = tursh.top();
        cout << p.x << " " << p.y << " " << p.z << endl;
        tursh.pop();
    }

    



   


    return 0;
}