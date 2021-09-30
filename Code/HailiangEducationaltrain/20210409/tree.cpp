#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>
using namespace std;


#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

typedef long long LL ;

inline LL read (register LL f = 0,register LL u = 0,register char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~ u + 1 : u ;
}
  
static const LL N = 3e5 + 5 , inf = 1e15 ;

LL n , m , k , u , v , w ;
LL f[N][2] ;
LL color[N] ;
vector <pair<LL,LL> > G[N] ;

inline void dfs(LL x,LL fa) {
    for (auto v : G[x]) {
        LL w = v.second ; LL son = v.first ;
        if (son == fa) continue ;
        dfs(son,x) ;
        f[x][0] += std::min(f[son][0],f[son][1]+w) ;
        f[x][1] += std::min(f[son][1],f[son][0]+w) ;
    }
    if (color[x]) f[x][color[x]-1] = inf ;
}

signed main(int argc,char *argv[]) {
    fre(tree) ;
    n = read() ;
    for (register LL i = 1 ; i < n ; ++i )     
        u = read() , v = read() , w = read() , G[u].push_back(make_pair(v,w)) , G[v].push_back(make_pair(u,w)) ;
    for (register LL i = 1 , m = read() ; i <= m ; ++i ) u = read() , color[u] = 1 ;
    for (register LL i = 1 , k = read() ; i <= k ; ++i ) u = read() , color[u] = 2 ;
    dfs(1,0) ;   
    printf("%lld\n",std::min(f[1][1],f[1][0])) ;
    fclose(stdin),fclose(stdout) ; return 0 ;
}