#include <bits/stdc++.h>

using namespace std ;

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 2e3 + 5 , M = 3e2 + 5 ;
const double infinity = 1e17 + 1e5 ;

int n , m , Edge , v , x , y , w ;
int dis[N][N] ; 
double f[N][N][2] , p[N] , ans ;
int lesson[N][2] ;

signed main() {
    memset(dis,63,sizeof dis) ;
    n = read() , m = read() , v = read() , Edge = read() ;
    for (int i = 1 ; i <= n ; ++i ) lesson[i][0] = read() ;
    for (int i = 1 ; i <= n ; ++i ) lesson[i][1] = read() ;
    for (int i = 1 ; i <= n ; ++i ) scanf("%lf",p + i) ;
    for (int i = 1 ; i <= Edge ; ++i )
        x = read() , y = read() , w = read() , dis[x][y] = dis[y][x] = min(dis[x][y],w) ;
    for (int k = 1 ; k <= v ; ++k )
        for (int i = 1 ; i <= v ; ++i ) 
            for (int j = 1 ; j <= v ; ++j )
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]) ;
    for (int i = 1 ; i <= v ; ++i ) dis[i][0] = dis[0][i] = dis[i][i] = 0 ; 
    for (int i = 0 ; i <= n ; ++i )
        for (int j = 0 ; j <= m ; ++j )
            f[i][j][1] = f[i][j][0] = infinity ;
    f[1][0][0] = f[1][1][1] = 0.0 ;
    for (int i = 2 ; i <= n ; ++i ) {
        f[i][0][0] = f[i - 1][0][0] + dis[lesson[i - 1][0]][lesson[i][0]] ;
        for (int j = 1 ; j <= min(i,m) ; ++j ) {
            int fr = lesson[i - 1][0] , fr1 = lesson[i - 1][1] , to = lesson[i][0] , to1 = lesson[i][1] ;
            f[i][j][0] = min(f[i][j][0], min(f[i - 1][j][0] + dis[fr][to], f[i - 1][j][1] + dis[fr][to] * (1 - p[i - 1]) + dis[fr1][to] * p[i - 1]));
            f[i][j][1] = min(f[i][j][1], min(f[i - 1][j - 1][0] + dis[fr][to] * (1 - p[i]) + dis[fr][to1] * p[i], f[i - 1][j - 1][1] + dis[fr1][to1] * p[i] * p[i - 1] + dis[fr1][to] * p[i - 1] * (1 - p[i]) + dis[fr][to1] * (1 - p[i - 1]) * p[i] + dis[fr][to] * (1 - p[i - 1]) * (1 - p[i])));
        }
    } ans = infinity ;
    for (int i = 0 ; i <= m ; ++i ) ans = min(ans,min(f[n][i][0],f[n][i][1])) ;
    return printf("%.2lf\n",ans) , 0 ;
} 