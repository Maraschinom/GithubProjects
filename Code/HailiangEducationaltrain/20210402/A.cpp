#pragma GCC diagnostic error "-std=c++11"

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define re register
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline
#define FOR(i,x,y) for(register LL i = x ; i <= y ; ++i )
#define ROF(i,x,y) for(register LL i = x ; i >= y ; --i )

typedef long long LL ;
typedef pair<LL,LL> PLL ;

inline LL read (re LL f = 0,re LL u = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~ u + 1 : u ;
}

inline string get (re string s = "",re char ch = getchar()) {
	for(;ch < 'a' || ch > 'z';ch = getchar()) 0 ;
	for(;ch >= 'a' && ch <= 'z';ch = getchar()) s.push_back(ch) ; return s ;
}

static const LL N = 105 ;
LL T , n , ans , j ;
LL w[N] , lim[N] ;

signed main (int argc , char *argv[]) {
    T = read() ;
    while (T--) {
        ans = 0 , j = 1 ;
        n = read() ;
        FOR (i,1,n) w[i] = read() ;
        FOR (i,1,n) lim[i] = read() ;
        std::sort(w+1,w+1+n) ;
        std::sort(lim+1,lim+1+n) ;
        FOR (i,1,n) {
            while (j <= n && lim[j] < w[i]) ++j ;
            if (j <= n && w[i] <= lim[j]) ++j , ++ans ;
        } printf("%lld\n",ans) ;
    }
    fclose(stdin),fclose(stdout) ; return 0 ;
}