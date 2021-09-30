#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;

inline LL read(register LL x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const int N = 1e3 + 5 ;

LL n , root , ans , u , v , f ;

struct Node {
    LL fa , val , t , id ;
    double w ;
}tr[N] ;

LL find() {
    LL idx = 0 ; double maxn = 0.0 ;
    for (int i = 1 ; i <= n ; ++i ) 
        if (i != root && tr[i].w > maxn) idx = i , maxn = tr[i].w ; return idx ;
}

int main() {
    n = read() , root = read() ;
    ans = 0 ;
    for (int i = 1 ; i <= n ; ++i )
        tr[i].val = read() , 
        tr[i].w += tr[i].val ,
        tr[i].id = i ,
        tr[i].t = 1 ,
        ans += tr[i].val ;
    for (int i = 1 ; i < n ; ++i )
        u = read() , v = read() , tr[v].fa = u ;
    for (int i = 1 ; i < n ; ++i ) {
        LL v = find() ;
        tr[v].w = 0 ;
        f = tr[v].fa ;
        ans += tr[v].val * tr[f].t ;
        for (int j = 1 ; j <= n ; ++j )
            if (tr[j].fa == v) tr[j].fa = f ;
        tr[f].val += tr[v].val ;
        tr[f].t += tr[v].t ;
        tr[f].w = (double)(tr[f].val * 1.0 / tr[f].t) ;
    } printf("%lld\n",ans) ;
}