#include <bits/stdc++.h>

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

typedef long long LL ;

using namespace std;

LL read(LL x = 0 ,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~x + 1 : x ;
}

const LL N = 2e5 + 5 ;

LL n , u , v , ans , res , root = 1 ;
LL dep[N] , siz[N] , arr[N] , f[N] ;
vector<LL> G[N] ;

void dfs(LL x,LL pre) {
    for (int i = 0 ; i < G[x].size() ; ++i) {
        LL v = G[x][i] ;
        if (v == pre) continue ;
        dep[v] = dep[x] + 1 ;
        dfs(v,x) ;
    } return ;
}

void dfs2(LL x,LL pre) {
    siz[x] = arr[x] ;
    for (int i = 0 ; i < G[x].size() ; ++i) {
        LL v = G[x][i] ;
        if (v == pre) continue ;
        dfs2(v,x) ;
        siz[x] += siz[v] ;
    } return ;
}

void dfs3(LL x,LL pre) {
    if (x != root) f[x] = f[pre] + siz[root] - 2 * siz[x] ;
    ans = max(f[x],ans) ;
    for (int i = 0 ; i < G[x].size() ; ++i) {
        LL v = G[x][i] ;
        if (v == pre) continue ;
        dfs3(v,x) ;
    } return ;
}

signed main() {
    // fre(pirate) ; 
    n  = read() ;
    for (int i = 1 ; i <= n ; ++i )
        arr[i] = read() , siz[root] += arr[i] ;
    for (int i = 1 ; i < n ; ++i )  
        u = read() , v = read() , G[u].push_back(v) , G[v].push_back(u) ;
    dfs(root,0) ;
    for (int i = 1 ; i <= n ; ++i ) 
        f[root] += arr[i] * dep[i] ; ans = res ;
    dfs2(root,0) ; dfs3(root,0) ;
    return printf("%lld\n",ans),0 ;
}