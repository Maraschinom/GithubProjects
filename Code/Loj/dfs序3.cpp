#pragma GCC diagnostic error "-std=c++11"
#include <cctype>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>

using namespace std ;

inline int read(register int x = 0,register bool f = false,register char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

#define lowbit(x) ((x)&(-x))

typedef long long LL ;

const int N = 1e6 + 5 ;
int Root , n , m , u , v , x , y , w , opt , T ;
int value[N] , siz[N] , fa[N] , son[N] ;
int jump[N] , dep[N] , dfn[N] , L[N] , R[N] ;
LL s[N][2] , sum[N] ;
vector<int> G[N] ;

inline void dfs1(int x,int pre) ; inline void dfs2(int x,int pre) ;

inline int Lca(int x,int y) ; inline void BIT_update(int x,LL w,int Type) ;

inline LL BIT_query(int x,int Type) ; inline void update_chain(int l,int r,int val) ;

inline LL query_node(int x) ; inline LL query_tree(int x) ;

signed main(void) {
    n = read() , m = read() , Root = read() ; 
    memset(son,-1,sizeof son) ; fa[Root] = Root ;
    for (register int i = 1 ; i <= n ; ++i ) value[i] = read() ;
    for (register int i = 1 ; i < n ; ++i ) 
        u = read() , v = read() , G[u].push_back(v) , G[v].push_back(u) ;
    dfs1(Root,Root) , dfs2(Root,Root) ; exit(0) ;
    for (int i = 1 ; i <= n ; ++i ) update_chain(i,i,value[i]) ;
    for (register int i = 1 ; i <= m ; ++i ) {
        opt = read() ;
        switch (opt) {
        case 1:
            x = read() , y = read() , w = read() ; update_chain(x,y,w) ;
            break ;
        case 2:
            x = read() ; query_node(x) ;
            break ;
        case 3:
            x = read() ; query_tree(x) ;
            break ;
        default:
            break;
        }
    }
}

inline void dfs1(int x,int pre) {
    siz[x] = 1 ;
    dfn[x] = ++ T ;
    L[x] = T ;
    for (auto v : G[x]) {
        if (v == pre) continue ;
        fa[v] = x ;
        dfs1(v,x) ;
        siz[x] += siz[v] ;
        dep[v] = dep[x] + 1 ;
        if (son[x] == -1 || siz[v] > siz[son[x]])
            son[x] = v ;
    } return R[x] = T , void() ;
}

inline void dfs2(int x,int pre) {
    jump[x] = pre ;
    if (son[x] != -1) dfs2(son[x],pre) ;
    for (auto v : G[x]) {
        if (v == pre || v == son[x]) continue ;
        dfs2(v,v) ;
    } return void() ;
}

inline int Lca(int x,int y){
    while (jump[x] != jump[y]){
        if (dep[jump[x]] > dep[jump[y]]) {x ^= y ; y ^= x ; x ^= y ;}
        y = fa[jump[y]] ;
    }
    return dep[x] > dep[y] ? y : x ;
}

inline void BIT_update(int id,LL w,int Type) {
    for (;id <= n;id += lowbit(id)) s[id][Type] += w ; return void() ;
}

inline LL BIT_query(int x,int Type) {
    LL ans = 0 ; for (;x;x -= lowbit(x)) ans += s[x][Type] ; return ans ;
}

inline void update_chain(int l,int r,int val) {
    int lca = Lca(l,r) ;
    BIT_update(L[x],val,0) ; BIT_update(L[y],val,0) ;
    BIT_update(L[lca],-val,0) ; BIT_update(L [fa[lca]],-val,0) ;
    BIT_update(L[x],val * L[x],1) ; BIT_update(L[y],val * L[y],1) ;
    BIT_update(L[lca],-val * L[lca],1) ; BIT_update(L[fa[lca]],-val * L[fa[lca]],1) ;
    return void() ;
}

inline LL query_tree(int x) {
    return BIT_query(R[x],0) - BIT_query(L[x] - 1,0) ;
}

inline LL query_node(int x) {
    return BIT_query(R[x],1) + (dep[x] - 1) * BIT_query(L[x] - 1,0) - BIT_query(L[x] - 1,1) - (dep[x] + 1) * BIT_query(R[x],0) ;
}