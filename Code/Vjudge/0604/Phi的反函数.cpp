#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std ;

typedef long long LL ;

int n ;
LL ans ;

inline bool isprime(LL x) {
    for (int i = 2 ; i * i <= x ; ++i )
        if (!(x % i)) return false ; return true ;
}

inline void dfs(int x,int now,LL sum) {
    if (x == 1) { return ans = min(ans,1LL * sum) , void() ; }
    if (x < now || sum > ans) return void() ;
    if (isprime(x + 1)) {return ans = min(ans,1LL * (x + 1) * sum) , void() ;}
    for (int i = now + 1 ; i * i <= x ; ++i ) {
        if (!(x % i)) {
            int Corresponding_number = x / i ;
            if (isprime(i + 1)) dfs(x / i , i , 1LL * sum * (i + 1)) ;
            if (isprime(Corresponding_number + 1)) dfs(x / Corresponding_number , Corresponding_number , 1LL * sum * (Corresponding_number + 1)) ;
        }
    } return void() ;
}

signed main(void) {
    ios::sync_with_stdio(false) ;
    cin.tie(0) , cout.tie(0) ;
    cin >> n ; ans = (1LL << 31) ; dfs(n,0,1) ;
    return printf("%lld\n",ans >= (1LL << 31) ? -1 : ans ) , 0 ;
}