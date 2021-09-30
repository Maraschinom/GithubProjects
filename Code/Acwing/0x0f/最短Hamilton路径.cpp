#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std ;

typedef long long LL ;

const int N = 20 ;

inline int read (register int x = 0 , register bool f = false , register char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f = (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 3) + (x << 1) + (ch^48) ; return f ? ~ x + 1 : x ;
}

int n ;
int f[N][N] , w[N][N] ;

signed main() {
    n = read() ;  
    for (int i = 0 ; i <= n ; ++i )
        for (int j = 0 ; j <= n ; ++j ) w[i][j] = read() ;
    memset(f,0x3f,sizeof f) ;
    f[1][0] = 0 ;
    for (int i = 1 ; i < 1 << n ; ++i )
        for (int j = 0 ; j <= n ; ++j ) if (i >> j & 1)
            for (int k = 0 ; k <= n ; ++k ) if (i >> k & 1) {
                f[i][j] = min(f[i][j],f[i^1 << j][k] + w[j][k]) ;
            }
    printf("%d\n",f[(1 << n) - 1][n - 1]) ;
}