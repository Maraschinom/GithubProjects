#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;

inline LL read(register LL x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const LL N = 5e5 + 5 ;

LL T ;
LL n , m , t , ans ;
LL a[N] , res[N] , b[N] ;

LL qpow(LL x,LL y){
    LL ans = 1 ; for (; y ; y >>= 1 , x = x*x ) if(y&1) ans *= x ; return ans ;
}

void merge(LL l,LL mid,LL r) {
    LL x = l , y = mid ;
    for (LL i = l ; i <= r ; ++i ) {
        if (y > r || x < mid && res[x] <= res[y]) b[i] = res[x ++] ;
        else b[i] = res[y ++] ;
    }
}

bool chk(LL l,LL mid,LL r) {
    for (LL i = mid ; i <= r ; ++i ) res[i] = a[i] ;
    sort(res + mid,res + r + 1) ;
    merge(l,mid,r) ;
    LL kk = 0 ;
    for (LL i = 0 ; i < (r - l + 1) / 2 && i < m ; ++i ) kk += (LL)qpow(b[r - i] - b[l + i],2) ;
    if (kk > t) return false ;
    else {
        for(LL i = l ; i <= r ; ++i) res[i] = b[i] ;
        return true ;
    }
}
void solve(LL l,LL r) {
    res[l] = a[l] ;
    LL len = 1 ;
    while (r <= n) {
        if (!len) {
            len = 1 ;   
            ++ ans , l = ++ r ;
            res[l] = a[l] ;
        } else if (r + len <= n&&chk(l,r + 1,r + len)) {
            r += len ; len <<= 1 ; if (r == n) break ;
        } else len >>= 1 ;
    }
    ans += (r == n) ;
}

signed main() {
    T = read() ;
    for (LL _ = 1 ; _ <= T ; ++_ ) {
        ans = 0 ;
        n = read() , m = read() , t = read() ;
        for (LL i = 1 ; i <= n ; ++i )
            a[i] = read() ;
        solve(1,1) ;
        printf("%lld\n",ans) ;
    }
}