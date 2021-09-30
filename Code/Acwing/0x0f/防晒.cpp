#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;

inline LL read(register LL x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const LL N = 2e3 + 5e2 + 5 ;

int n , m , u , v , ans ;
pair<int,int> cows[N] ;
map<int,int> spf ;

signed main() {
    n = read() , m = read() ;
    for (int i = 1 ; i <= n ; ++i ) cows[i].first = read() , cows[i].second = read() ;
    sort(cows + 1 , cows + 1 + n) ;
    for (int i = 1 ; i <= m ; ++i ) 
        u =read() , v = read() , spf[u] += v ;
    spf[0] = spf[1001] = n ;
    for (int i = n ; i ; --i ) {
        auto it = spf.upper_bound(cows[i].second) ;
        -- it ;
        if (it -> first >= cows[i].first && it -> first <= cows[i].second) {
            ++ ans ;
            if (-- it -> second == 0) spf.erase(it) ;
        }
    } return printf("%d\n",ans) , 0 ;
}