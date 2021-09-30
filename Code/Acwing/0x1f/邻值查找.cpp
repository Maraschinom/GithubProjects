#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <cctype>

typedef long long LL ;

using namespace std ;

LL read(LL x = 0 ,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ; return f ? ~ x + 1 : x ;
}

const int N = 1e5 + 5 ;
const LL inf = 1e15 ;
set<LL> s ;
int n ;
LL ans , u , v ;
LL arr[N] ;
map<LL,int> min_idx ;

void solve(LL x) {
    auto it = s.lower_bound(x) ;
    if(it == s.end()) u = inf ;
    else u = *it ;
    if(it == s.begin()) v = inf ;
    else -- it , v = *it ;
    if (abs(x - u) > abs(x - v)) {
        ans = abs(x - v) ;
        printf("%lld %d\n",ans,min_idx[v]) ;
    }
    else if (abs(x - u) == abs(x - v)) {
        ans = abs(x - v) ;
        printf("%lld %d\n",ans,min_idx[min(u,v)]) ;
    } else {
        ans = abs(x - u) ;
        printf("%lld %d\n",ans,min_idx[u]) ;
    }
    s.insert(x) ;
}

signed main() {
    n = read() ;
    for (auto i = 1 ; i <= n ; ++i ) arr[i] = read() ;
    for (auto i = 1 ; i <= n ; ++i ) 
        if (min_idx.find(arr[i]) == min_idx.end()) min_idx[arr[i]] = i ;
    s.insert(arr[1]) ;
    for (auto i = 2 ; i <= n ; ++i )
        solve(arr[i]) ;
    return 0 ;
}