#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>
using namespace std;

typedef long long LL ;
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

inline LL read (register LL f = 0,register LL u = 0,register char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~ u + 1 : u ;
}

static const LL N = 2e3+5 ;
LL n , T , ans , prex , prey ;
LL p[N] , cnt[N] , f[N][N] ;

inline void find() {
    for (register LL i = 1 ; i <= n ; ++i ) for (register LL j = 1 ; j <= n ; ++j )
        if (f[i][j] == n-1 ) {prex = i , prey = j ; return ;}

}

signed main(int argc,char *argv[]) {
	fre(permutation) ;
    T = read() ;
    while (T--) {
        memset(cnt,0,sizeof cnt) ;
        n = read() ;
        for (register LL i = 1 ; i <= n ; ++i )
            for (register LL j = 1 ; j <= n ; ++j )
                f[i][j] = read() ;
        find() ;
        LL mx = std::max(prex,prey) , mn = std::min(prex,prey) ;
        p[mx] = n , p[mn] = n-1 ;
        ans = 0 ;
        for (register LL i = 1 ; i <= n ; ++i )
            if (i != prex && i != prey ) p[i] = f[mn][i] ;       
        for (register LL i = 1 ; i <= n ; ++i )
            for (register LL j = 1 ; j <= n ; ++j )
                ans |= ((f[i][j] != std::min(p[i],p[j])) && i != j) ;
        for (register LL i = 1 ; i <= n ; ++i ) ++cnt[p[i]] ;
        for (register LL i = 1 ; i <= n ; ++i ) ans |= (cnt[i]^1) ;
        ans = !ans ? 2 : -1 ;
        printf("%lld\n",ans) ;
        if (ans > 0)
            for (register LL k = 1 ; k <= n ; ++k ) printf("%lld%c",p[k],k==n?'\n':' ') ;
    }
    fclose(stdin),fclose(stdout) ; return 0 ;
}