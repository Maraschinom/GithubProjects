#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;

inline LL read(register LL x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const int N = 1e5 + 5 ;

int n , u , v , h , p , m , ans ;
int d[N] ;

map<pair<int,int>,bool> vis ;

signed main() {
    n = read() ;
    p = read() , h = read() , m = read() ;
    for (int i = 1 ; i <= m ; ++i ) {
        u = read() , v = read() ;
        if (u > v) swap(u,v) ;
        if (vis.find(make_pair(u,v)) != vis.end()) continue ;
        vis[make_pair(u,v)] = true ;
        -- d[u + 1] , ++d[v] ;
    }
    for (int i = 1 ; i <= n ; ++i )
        ans += d[i] , printf("%d\n",ans + h) ;
}