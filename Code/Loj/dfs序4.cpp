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

const int N = 1e6 + 5 ;
int Root , n , m , u , v , x , y , opt ;
int value[N] , siz[N] , fa[N] , son[N] , jump[N] , dep[N] ;
vector<int> G[N] ;

inline void dfs1(int x,int pre) ;

inline void dfs2(int x,int pre) ;

inline int Lca(int x,int y) ;

inline void BIT_update(int x,int w) ;

inline void BIT_query(int x) ;

inline void query_chain(int x) ;

inline void update_node(int Root,int id,int w) ;

inline void update_tree(int Root,int l,int r,int w) ;

inline void query_chain(int Root,int l,int r) ;

inline void query_tree(int Root,int x) ;

signed main(void) {
    n = read() , m = read() , Root = read() ; memset(son,-1,sizeof son) ; fa[Root] = Root ;
    for (register int i = 1 ; i <= n ; ++i ) value[i] = read() ;
    for (register int i = 1 ; i < n ; ++i ) u = read() , v = read() , G[u].push_back(v) , G[v].push_back(u) ;
    dfs1(Root,-1) , dfs2(Root,-1) ;
    for (register int i = 1 ; i <= m ; ++i ) {
        opt = read() , x = read() , y = read() ;
        switch (opt) {
        case 1:

            break ;
        case 2:

            break ;
        case 3:

            break ;
        default:
            break;
        }
    }
}

inline void dfs1(int x,int pre) {
    siz[x] = 1 ;
    for (auto v : G[x]) {
        if (v == pre) continue ;
        fa[v] == x ;
        dfs1(v,x) ;
        siz[x] += siz[v] ;
        dep[v] = dep[x] + 1 ;
        if (son[x] == -1 || siz[v] > siz[son[x]])
            son[x] = v ;
    } return void() ;
}

inline void dfs2(int x,int pre) {
    jump[x] = pre ;
    if (son[x] != -1) dfs2(son[x],x) ;
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