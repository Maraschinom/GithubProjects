#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std ;

inline int read(register int x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const int N = 5e3 + 5 ;

int n , r , u , v , w , mx , mxx , ans ;
int a[N][N] ;

signed main() {
    n = read() , r = read() ;
    mx = mxx = r ;
    for (int i = 1 ; i <= n ; ++i ) {
        u = read() ; v = read() ;
        ++ u , ++ v ;
        w = read() ;
        a[u][v] += w ; // 不同炸弹可能在同一位置
        mx = max(mx,u) ; mxx = max(mxx,v) ;
    }
    for (int i = 1 ; i <= mx ; ++i )
        for (int j = 1 ; j <= mxx ; ++j )
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] ;
    for (int i = r ; i <= mx ; ++i )
        for (int j = r ; j <= mxx ; ++j )
            ans = max(a[i][j] - a[i - r][j] - a[i][j - r] + a[i - r][j - r] , ans) ;
    printf("%d\n",ans) ;
}