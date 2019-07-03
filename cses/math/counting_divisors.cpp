#include <bits/stdc++.h>
#define m 1000010

int d[m], n, x, i=2, j;

int main() {
    
    std::cin >> n;
    
    for (; i < m; i ++) 
        for (j = i; j < m; j += i)
            d[j] ++;


    while(n--){
        std::cin >> x;
        std::cout << d[x] + 1 << ' ';
    }

    return 0;
}