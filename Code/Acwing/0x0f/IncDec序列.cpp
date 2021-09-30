#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;

inline LL read(register LL x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const int N = 1e5 + 5 ;

LL n , a[N] , c[N] ;
LL sum1 , sum2 ;

signed main() {
    n = read() ;
    for (int i = 1 ; i <= n ; ++i ) a[i] = read() ;
    for (int i = n ; i > 1 ; --i ) a[i] -= a[i-1] ;
    for (int i = 2 ; i <= n ; ++i )
        if (a[i] < 0) sum1 -= a[i] ;
        else sum2 += a[i] ;
    printf("%lld\n%lld\n",max(sum1,sum2),abs(sum1-sum2) + 1) ;
}