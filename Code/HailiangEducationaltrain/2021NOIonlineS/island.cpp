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
#define FOR(i,x,y) for(LL i = x ; i <= y ; ++i )
#define ROF(i,x,y) for(LL i = x ; i >= y ; --i )

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

inline LL qpow(LL x,LL y) {
    LL ans = 1  ; for (;y;y>>=1,x*=x) if (y&1) ans*=x ; return ans ;
}

const LL N = 1e5+5 , M = 16777215 , inf = 1e15 ;
LL n = 0 , q  = 0 , ans  = 0 , minn = inf , mxx = -inf ;
bool istask1 = false , istask2 = true , istask3 = true ;

struct island {
    LL a , b ;
} land[N] ;

struct ask {
    LL l , r , c , d ;
} Q[N] ;

inline void solve() { // ok
    FOR(i,1,q) {
        ans = 0ll ;
        FOR(j,Q[i].l,Q[i].r) {
            if ( (Q[i].c ^ land[j].a) <= std::min(Q[i].d,land[j].b) ) ++ans ;
        }
        printf("%lld\n",ans) ; 
    } return void() ;
}

inline void solve2() {
    FOR(i,1,q) {
        ans = 0ll ;
        FOR(j,Q[i].l,Q[i].r)
            if ( (Q[i].c ^ land[j].a) <= Q[i].d ) ++ans ;
        printf("%lld\n",ans) ;   
    } return void() ;
}

inline void solve3() {
    FOR(i,1,q) {
        ans = 0ll ;
        FOR(j,Q[i].l,Q[i].r) 
            if ( (Q[i].c ^ land[j].a) <= land[j].b) ++ans ;
        printf("%lld\n",ans) ;
    } return void() ;
}

signed main(int argc,char *argv[]) {
	fre(island) ;
    n = read() , q = read() ;
    FOR(i,1,n) land[i].a = read() , land[i].b = read() , minn = std::min(minn,land[i].b) , mxx = std::max(mxx,land[i].b) ;
 	if (n <= 8000) istask1 = true ;
    FOR(i,1,q) Q[i].l = read() , Q[i].r = read() , Q[i].c = read() , Q[i].d = read() ;
    FOR(i,1,q) {
        if (Q[i].d > minn) istask2 = false ;
        if (Q[i].d < mxx) istask3 = false ;
    }
    if (istask1) solve() ;
    else if (istask2) solve2() ;
    else if (istask3) solve3() ;
    else solve() ;
    fclose(stdin) , fclose(stdout) ;
    return 0 ; 
}
/*
Input :
4 2
1 1
4 2
5 1
2 7
1 4 6 5
2 4 3 3

Input :
20 10
215 144
2 110
174 132
214 142
116 108
155 192
236 208
216 214
99 220
236 118
190 81
230 131
10 238
189 198
183 13
45 193
14 234
208 192
126 19
49 38
7 14 251 184
2 18 89 76
11 15 49 196
8 11 83 139
10 15 119 239
9 16 148 120
11 17 225 34
15 16 3 46
14 15 86 227
7 18 252 103

*/ 