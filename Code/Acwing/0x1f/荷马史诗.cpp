#include <bits/stdc++.h>

using namespace std ;

typedef pair<__int64,__int64> pii ;

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const __int64 N = 1e6 + 5 , M = 10 ;
__int64 n , ans , mx , k , sum , len , dep ;
__int64 frequecy[N] ;
priority_queue<pii,vector<pii>,greater<pii> > Q ;

signed main() {
    n = read() ; k = read() ;
    for (int i = 1 ; i <= n ; ++i ) frequecy[i] = read() , Q.push(make_pair(frequecy[i],0)) ;
    while (Q.size() >= k) {
        sum = dep = 0 ;
        for (int i = 1 ; i <= k ; ++i ) {
            sum += Q.top().first , dep = max(dep,Q.top().second) ;
            Q.pop() ;
        } ans += sum ;
        Q.push(make_pair(sum,dep + 1)) ;
    }
    printf("%lld\n%lld\n",ans,Q.top().second) ;
}