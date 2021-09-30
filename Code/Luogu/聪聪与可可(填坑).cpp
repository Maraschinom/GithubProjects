#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;
typedef pair<int,int> PII ;

#define Make_Pair make_pair

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 1e3 + 5 ;
int n , e , c , m , u , v ;
int nxt[N][N] , dis[N][N] , deg[N] ;
double f[N][N] , ans ;
vector<int> G[N] ;

double calc(int x,int y) {
    if (f[x][y] != -1.0) return f[x][y] ; //记忆化
    if (x == y) return f[x][y] = 0.0 ;
    if (nxt[x][y] == y) return f[x][y] = 1.0 ;
    if (nxt[nxt[x][y]][y] == y) return f[x][y] = 1.0 ;
    for (auto v : G[y])
        f[x][y] += calc(nxt[nxt[x][y]][y],v) ;
    f[x][y] = (calc(nxt[nxt[x][y]][y],y) + f[x][y]) / (deg[y] + 1.0) + 1.0 ;
    return f[x][y] ;
}

signed main() {
    n = read() , e = read() , c = read() , m = read() ;
    for (int i = 1 ; i <= e ; ++i )
        u = read() , v = read() ,
        G[u].push_back(v) , G[v].push_back(u) ,
        ++ deg[u] , ++ deg[v] ;
    for (int i = 0 ; i <= n ; ++i )
        for (int j = 0 ; j <= n ; ++j )
            f[i][j] = -1.0 ;
    for (int i = 1 ; i <= n ; ++i ) {
        queue<PII> q ;
        q.push(Make_Pair(i,dis[i][i] = 0)) ;
        while (q.size()) {
            auto x = q.front() ; q.pop() ;
            for (auto v : G[x.first]) if (!dis[i][v])
                q.push(Make_Pair(v,dis[i][v] = dis[v][i] = x.second + 1)) ;
        }
    }
    memset(nxt,0x3f,sizeof nxt) ;
    for (int i = 1 ; i <= n ; ++i )
        for (auto v : G[i])
            for (int j = 1 ; j <= n ; ++j )
                if (dis[i][j] == dis[v][j] + 1)
                    nxt[i][j] = min(nxt[i][j],v) ;
	for (int i = 1 ; i <= n ; ++i )
        for (int j = 1 ; j <= n ; ++j )
            printf("%d%c",nxt[i][j],j == n?'\n':' ') ;
    ans = calc(c,m) ;
    printf("%.3lf\n",ans) ;
    return 0 ;
}