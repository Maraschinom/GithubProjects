#include <bits/stdc++.h>

using namespace std ;

inline int read(register int x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const int N = 1e3 + 5 ;

int n , d , ans ;
double pos ;

struct Node{
    int x , y ;
    double l , r ;
    inline bool operator < (const Node& o) const {
        return this -> x < o.x ;
    }
} island[N] ;

signed main() {
    n = read() , d = read() ;
    for (int i = 1 ; i <= n ; ++i ) 
        island[i].x = read() , island[i].y = read() ;
    for (int i = 1 ; i <= n ; ++i ) if (island[i].y > d) return puts("-1") , 0 ;
    for (int i = 1 ; i <= n ; ++i )
        island[i].l = island[i].x - sqrt(d * d - island[i].y * island[i].y) ,
        island[i].r = island[i].x + sqrt(d * d - island[i].y * island[i].y) ;
    pos = - 1e9 ;
    sort(island + 1 , island + 1 + n) ;
    for (int i = 1 ; i <= n ; ++i ) {
        if (pos < island[i].l) {
            ++ ans ;
            pos = island[i].r ;
        } else {
            pos = min(pos,island[i].r) ;
        }
    } printf("%d\n",ans) ;
}