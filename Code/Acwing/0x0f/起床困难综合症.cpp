#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdio>

using namespace std ;

typedef long long LL ;

LL read(register LL x = 0,register bool f = false,register char ch = getchar()) {
    for(;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for(;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x+1 : x ;
}

const LL N = 1e6 + 5 ;
LL n , m , ans ;
char s[4] ;
LL op[N] , w[N] ;

bool calc(bool x, LL j)
{
    for (int i = 1 ; i <= n ; ++i )
        if (op[i] == 1) x |= w[i] >> j & 1 ;
        else if (op[i] == 2) x ^= w[i] >> j & 1 ;
        else x &= w[i] >> j & 1 ;
    return x ;
}

signed main() {
    n = read() , m = read() ;
    for (LL i = 1 ; i <= n ; ++i ) {
        scanf("%s",s) ;
        w[i] = read() ;
        if (s[0] == 'O') op[i] = 1 ;
        else if (s[0] == 'X') op[i] = 2 ;
        else op[i] = 3 ;
    }
    for (LL i = 30 ; ~i ; --i ) {
        if (m >> i) {
            int x = calc(0,i) , y = calc(1,i) ;
            if (x >= y) ans |= x << i ;
            else ans |=  y << i , m -= 1 << i ;
        } else ans |= calc(0,i) << i ;
    } printf("%lld\n",ans) ;
    return 0 ; 
}