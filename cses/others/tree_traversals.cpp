#include <bits/stdc++.h>
using namespace std;

#define nmax 100005


int n, preord[nmax], inord[nmax];


void recurse(int prebeg, int prefin, int inbeg, int infin) {
    
    if (prebeg == prefin) {   
        return ;
    }
                            
    int midin = -1;
    for (int i = inbeg; i <= infin; i ++) {
        if (preord[prebeg] == inord[i]) {
            midin = i;
            break;    
        }    
    }    
    
    assert(midin != -1);

    int leftlen = midin - inbeg;
    int p_l_beg = prebeg + 1;
    int p_l_fin = prebeg + leftlen;
    int p_r_beg = prebeg + leftlen + 1;
    int p_r_fin = prefin;
    
    int i_l_beg = inbeg;
    int i_l_fin = midin - 1;
    int i_r_beg = midin + 1;
    int i_r_fin = infin;

    if (p_l_beg <= p_l_fin) {
    recurse(p_l_beg, p_l_fin, i_l_beg, i_l_fin);
    cout << preord[p_l_beg] << " ";
   }
   if (p_r_beg <= p_r_fin) {
    recurse(p_r_beg, p_r_fin, i_r_beg, i_r_fin);
    cout << preord[p_r_beg] << " ";
   }
}


signed main() {
    
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> preord[i];
    }
    for (int i = 0; i < n; i ++) {
        cin >> inord[i];
    }
    

    recurse(0, n - 1, 0, n - 1);
    cout << preord[0] << endl;


    return 0;
}