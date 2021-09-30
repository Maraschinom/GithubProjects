#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <map>

using namespace std ;

const int N = 35 , M = 305 , mod = 8 ;
const int dx[] = {1,0,-1,-1,-1,0,1,1} ;
const int dy[] = {1,1,1,0,-1,-1,-1,0} ;

int n , ans ;
int t[N] ;
int vis[M][M] ;
int f[M][M][9][N] ;

inline void dfs(int x,int y,int dir,int step) {
    if (f[x][y][dir][step]) return void() ;
    f[x][y][dir][step] = true ;
    int tmp = t[step] - 1 ; vis[x][y] = true ;
    while (tmp) vis[x += dx[dir]][y += dy[dir]] = true , -- tmp ;
    if (step == n) return void() ; ++ step ;
    int ldir = (dir - 1 + mod) % mod ;
    int rdir = (dir + 1 + mod) % mod ;
    dfs(x + dx[ldir],y + dy[ldir],ldir,step) ;
    dfs(x + dx[rdir],y + dy[rdir],rdir,step) ;
}

signed main(int argc,char *argv[]) {
    ios::sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ; cin >> n ;
    for (int i = 1 ; i <= n ; ++i ) cin >> t[i] ; 
    dfs(151,151,1,1) ;
    for (int i = 1 ; i < M ; ++i )
        for (int j = 1 ; j < M ; ++j )
            ans += vis[i][j] ;
    printf("%d\n",ans) ; return 0 ;
}