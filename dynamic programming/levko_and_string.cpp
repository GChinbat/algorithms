#include <bits/stdc++.h>
using namespace std;

string a = "az";
string b = "abz";
string c = "acz";
string d = "adz"; 

int get_buety(string t) {

    string s = "abcd";
   // cout << " get ::: " << endl;
   // cout << t << endl;
   // cout << endl;


    int cnt = 0;
    for (int i = 0; i < s.size(); i ++) {
        for (int j = i; j < s.size(); j ++) {
             string tmps = "";
             string tmpt = "";
             for (int h = i; h <= j; h++) {
                 tmps += s[h];
                 tmpt += t[h];
                 
             }
             if (tmpt > tmps) {
                    cnt ++;
                   // cout << tmpt << " > " << tmps << endl;
             }

             
        }
    }
 //   cout << endl;
    return cnt;

}

signed main() {

    freopen("out", "w", stdout);
        

    vector<string > aa;
    
    for (auto ach: a) {
        for (auto bch : b) {
            for (auto cch : c) {
                for (auto dch : d) {
                    string tmp = "";
                    tmp += ach;
                    tmp += bch;
                    tmp += cch;
                    tmp += dch;
                    aa.push_back(tmp);
                }
            }
        }
    }

   
    cout << "abcd" << endl;
    cout << endl;

   // cout << get_buety("wxyz");
   // return 0;

    for (auto s : aa) {

        int tt = get_buety(s);
        if (tt == 7) 
        cout << s << " ->  " << get_buety(s) << endl;
     //   break;
    }

         
    
    
    return 0;
}