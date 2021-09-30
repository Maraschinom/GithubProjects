#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;

inline LL read (register LL x = 0 , register bool f = false , register char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x+1 : x ;
}

LL x , y , mod ;

inline LL qpow(LL x,LL y) {
    LL ans = 1 ;
    for ( ; y ; y >>= 1 , x = (x*x) % mod ) if(y&1) ans = (ans*x) % mod ; return ans % mod ; 
}


signed main() {
    x = read() ;
    y = read() ;
    mod = read() ;
    printf("%lld\n",qpow(x,y)) ;
    return 0 ;  
}