#include <bits/stdc++.h>

using namespace std ;

inline int read(register int x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const int N = 1e5 + 5 ;
int n , idx , ans ;
int pos[N] ;

signed main() {
    n = read() ;
    for (int i = 1 ; i <= n ; ++i ) pos[i] = read() ;
    sort(pos + 1 , pos + 1 + n) ;
    if (n&1) idx = (n+1) >> 1 ;
    else idx = n >> 1 ;
    for (int i = 1 ; i <= n ; ++i ) ans = ans + abs(pos[i] - pos[idx]) ;
    printf("%d\n",ans) ;
}