#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;

inline LL read(register LL x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const LL N = 1e5 + 5 ;

int n , m , k , u , v , s1 , s2 ;
int a[N] , b[N] , f[N] ;

LL solve(int A[N],int x,int type) {
    LL ans = 0 ;
    for (int i = 1 ; i <= x ; ++i ) A[i] -= type ? s1 / x : s2 / x, f[i] = f[i - 1] + A[i] ;
    sort(f + 1,f + 1 + x) ;
    for (int i = 1 ; i <= x ; ++i ) ans += abs(f[i] - f[(x + 1) >> 1]) ; return ans ;
}

signed main() {
    n = read() , m = read() , k = read() ;
    for (int i = 1 ; i <= k ; ++i ) u = read() , v = read() , ++ a[u] , ++b[v] ;
    for (int i = 1 ; i <= n ; ++i ) s1 += a[i] ;
    for (int i = 1 ; i <= m ; ++i ) s2 += b[i] ;
    if (!(s1 % n) && !(s2 % m)) printf("both %lld\n",solve(a,n,1) + solve(b,m,0)) ;
    else if (!(s1 % n)) printf("row %lld\n",solve(a,n,1)) ;
    else if (!(s2 % m)) printf("column %lld\n",solve(b,m,0)) ;
    else puts("impossible") ; return 0 ;
}