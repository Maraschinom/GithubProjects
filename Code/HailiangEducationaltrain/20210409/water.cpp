// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
typedef long long LL ;

inline LL read (register LL f = 0,register LL u = 0,register char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~ u + 1 : u ;
}

static const LL N = 305 ;
LL n , m ;
LL h[N][N] ;
LL water[N][N] ;
bool vis[N][N] ;

struct Node {
    LL x , y , minn ;
    friend bool operator < (const Node a,const Node b) {
        return a.minn > b.minn ;
    }
} ;

priority_queue<Node> Q ;

const LL dx[5] = {0,1,-1,0,0} ;
const LL dy[5] = {0,0,0,-1,1} ;

signed main(int argc,char *argv[]) {
    fre(water) ; 
    n = read() , m = read() ;
    for (register LL i = 1 ; i <= n ; ++i ) 
        for (register LL j = 1 ; j <= m ; ++j ) {
            h[i][j] = read() ;
            if (i == 1 || i == n || j == 1 || j == m ) {
                vis[i][j] = true ;
                if (h[i][j] < 0) water[i][j] = -h[i][j] , Q.push((Node){i,j,0ll}) ;
                else Q.push((Node){i,j,h[i][j]}) ; 
            }
        }
    for (;Q.size();) {
        Node u = Q.top() ; Q.pop() ;
        for (LL i = 1 ; i <= 4 ; ++i ) {
            LL x = u.x + dx[i] , y = u.y + dy[i] ;
            if (!(x&&x<=n&&y&&y<=m&&!vis[x][y])) continue ;
            vis[x][y] = true ;
            if (h[x][y]-u.minn>=0) Q.push((Node){x,y,h[x][y]}) ;
            else water[x][y] = u.minn - h[x][y], Q.push((Node){x,y,u.minn}) ;
        }
    }
    for (register LL i = 1 ; i <= n ; ++i ) 
        for (register LL j = 1 ; j <= m ; ++j ) 
            printf("%lld%c",water[i][j],j == m?'\n' : ' ') ;
    fclose(stdin),fclose(stdout) ; return 0 ;
}