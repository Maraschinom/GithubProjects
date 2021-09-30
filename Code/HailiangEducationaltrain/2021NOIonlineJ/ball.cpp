#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

#define re register
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline  
#define FOR(i,x,y) for(LL i = x ; i <= y ; ++i )
#define ROF(i,x,y) for(LL i = x ; i >= y ; --i )

typedef long long LL ; typedef pair<LL,LL> PLL ;

inline LL read (re LL f = 0,re LL u = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~ u + 1 : u ;
}

inline string get (re string s = "",re char ch = getchar()) {
	for(;!isalpha(ch);ch = getchar()) 0 ;
	for(;isalpha(ch);ch = getchar()) s.push_back(ch) ; return s ;
}

bool p ;
static const LL N = 250+5 , M = 50 ;
LL n , m , q , sx , sy , ssx , ssy ;
LL x[N],y[N] ;
bool vis[M][M][M][M];
char map[N][N] ;
bool c ;

struct Node {
    LL x1 , y1 , x2 , y2 ;
    LL step ;
} ;

const LL dx[] = {1,-1,0,0} ;
const LL dy[] = {0,0,1,-1} ;

inline PLL fall (LL x,LL y,LL dir) {
    while(x>=1&&x<=n&&y>=1&&y<=n&&map[x][y] != '#') x-=dx[dir] , y-=dy[dir] ;
    return make_pair(x,y) ;
}

inline LL bfs(LL x1,LL y1,LL x2,LL y2) {
    queue <Node> q ;
    q.push((Node){x1,y1,x2,y2,0}) ;
    while (q.size()) {
        Node u = q.front() ; q.pop() ;
        if (u.x1 == u.x2 && u.y1 == u.y2) return u.step ;
        for (LL i = 0 ; i <= 4 ; ++i ) {
            LL xx = fall(u.x1,u.y1,i).first ;
            LL yy = fall(u.x1,u.y1,i).second ;
            LL xx1 = fall(u.x2,u.y2,i).first ;
            LL yy1 = fall(u.x2,u.y2,i).second ;
            if (xx>=1&&xx<=n&&yy>=1&&yy<=n&&xx1>=1&&xx1<=n&&yy1>=1&&yy1<=n&&!vis[xx][yy][xx1][yy1])q.push((Node){xx,yy,xx1,yy1,u.step+1}) ;
            vis[xx][yy][xx1][yy1] = true ;
        }
    }
}

signed main() {
	// fre(ball) ;
    n = read() , m = read() , q = read() ;
    // if (n == 4 && m == 4) return puts("1\n0\n3"),0 ;
    FOR(i,1,m) x[i] = read() , y[i] = read() , map[x[i]][y[i]] == '#' ;
    if (n == 2) {
        FOR(i,1,q) {
                sx = read() , sy = read() ;
                ssx = read() , ssy = read() ;
                if (sx == ssx && sy == ssy) {
                    puts("0") ;
                    continue ;
                }
                if (sx == ssx || sy == ssy )
                    puts("1") ;
                else {
                    if (!m) puts("2") ;
                    else puts("-1") ;
                }
            }
    } else FOR(i,1,q) {
        sx = read() , sy = read() ;
        ssx = read() , ssy = read() ;
        if (bfs(sx,sy,ssx,ssy)) printf("%lld\n",bfs(sx,sy,ssx,ssy)) ;
        else printf("%lld\n",-1) ;
    }
	fclose(stdin) , fclose(stdout) ; return 0 ; 
}