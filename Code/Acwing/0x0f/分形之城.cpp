#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;
typedef pair<long long,long long> PLL ;

inline LL read(register LL x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

int T ;
LL n , a , b ;

PLL solve (LL n,LL m) {
    if (n == 0) return make_pair(0,0) ;
    LL len = 1LL << (n - 1) , cnt = 1LL << (2 * n - 2) ; //len 等级为n区块长度 m%cnt 等级为n的区块里所属块里的编号
    PLL pos = solve(n - 1,m % cnt) ;
    LL x = pos.first , y = pos.second ;
    LL Type = m / cnt ; //等级为n的区块里属于哪个块
    if (Type == 0)
        return {y,x} ;
    else if (Type == 1)
        return make_pair(x,y + len) ;
    else if (Type == 2)
        return make_pair(x + len,y + len) ;
    else if (Type == 3)
        return make_pair(2 * len - 1 - y , len - 1 - x) ;
}

signed main() {
    T = read() ;
    while (T--) {
        n = read() ; 
        a = read() ; 
        b = read() ;
        PLL p1 = solve(n,a - 1) ;
        PLL p2 = solve(n,b - 1) ;
        LL x = p1.first - p2.first , y = p1.second - p2.second ;
        printf("%0.lf\n",sqrt(x * x + y * y)*10) ;
    }
}