#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;

inline LL read (register LL x = 0 , register bool f = false , register char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x+1 : x ;
}

LL a , b , mod ;

inline LL Mul(LL x,LL y) {
    return ( x * y - (LL) ( (long double) x / mod * y ) * mod + mod ) % mod ;
}

inline LL mul(LL x,LL y) {
    x %= mod , y %= mod ;
    LL ans = 0LL ;
    for ( ; y ; y >>= 1 , x = (x+x) % mod ) if(y&1) ans = (ans+x) % mod ; return ans % mod ;
}

inline LL qpow(LL x,LL y) {
    x %= mod , y %= mod ;
    LL ans = 1LL ;
    for ( ; y ; y >>= 1 , x = mul(x,x) % mod ) if(y&1) ans = mul(ans,x) % mod ; return ans % mod ; 
}


signed main() {
    a = read() ;
    b = read() ;
    mod = read() ;
    a %= mod , b %= mod ;
    printf("%lld\n",mul(a,b) % mod) ;
    return 0 ;  
}