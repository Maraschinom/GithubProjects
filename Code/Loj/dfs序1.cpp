#pragma GCC diagnostic error "-std=c++11"
#include <cctype>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>

using namespace std ;

typedef long long LL ;

inline int read(register int x = 0,register bool f = false,register char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

inline LL readLL(register LL x = 0,register bool f = false,register char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

#define lowbit(x) ((x)&(-x))

const int N = 1e6 + 5 ;
int Root , n , m , u , v , x , opt , T ;
LL y ;
int siz[N] , fa[N] , son[N] , jump[N] , dep[N] , dfn[N] , L[N] , R[N] ;
LL s[N] , value[N] ;
vector<int> G[N] ;

inline void dfs1(int id,int pre) ;

inline void BIT_update(int id,LL w) ;

inline LL BIT_query(int id) ;

inline void update_node(int Root,int id,LL w) ;

inline LL query_tree(int Root,int id) ;

signed main(void) {
    n = read() , m = read() , Root = read() ; memset(son,-1,sizeof son) ; fa[Root] = Root ;
    for (register int i = 1 ; i <= n ; ++i ) value[i] = read() ;
    for (register int i = 1 ; i < n ; ++i ) u = read() , v = read() , G[u].push_back(v) , G[v].push_back(u) ;
    dfs1(Root,-1) ;
    for (register int i = 1 ; i <= m ; ++i ) {
        opt = read() ;
        switch (opt) {
        case 1:
            x = read() , y = readLL() ;
            update_node(Root,x,y) ;
            break ;
        case 2:
            x = read() ;
            printf("%lld\n",query_tree(Root,x)) ;
            break ;
        default:
            break;
        }
    }
}

inline void dfs1(int id,int pre) {
    siz[id] = 1 ;
    dfn[id] = ++ T ;
    BIT_update(T,value[id]) ;
    L[id] = T ;
    for (auto v : G[id]) {
        if (v == pre) continue ;
        fa[v] = id ;
        dfs1(v,id) ;
        siz[id] += siz[v] ;
        dep[v] = dep[id] + 1 ;
        if (son[id] == -1 || siz[v] > siz[son[id]])
            son[id] = v ;
    } return R[id] = T , void() ;
}

inline void BIT_update(int id,LL w) {
    for (;id <= n;id += lowbit(id)) s[id] += w ; return void() ;
}

inline LL BIT_query(int id) {
    LL ans = 0 ; for (;id;id -= lowbit(id)) ans += s[id] ; return ans ;
}

inline void update_node(int Root,int id,LL w) {
    BIT_update(dfn[id],w) ; return void() ;
}

inline LL query_tree(int Root,int id) {
    return BIT_query(L[id] + siz[id] - 1) - BIT_query(L[id] - 1) ;
}