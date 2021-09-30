// #pragma GCC diagnostic error "-std=c++11"
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std ;

#define re register

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

#define inl inline 

#define FOR(i,x,y) for(int i = x ; i <= y ; ++i )
#define ROF(i,x,y) for(int i = x ; i >= y ; --i )

typedef long long LL ;
typedef pair<LL,LL> PLL ;

inline LL read (re LL f = 0,re LL u = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~ u + 1 : u ;
}

const LL dx[] = {1,-1,0,0,0,0} ;
const LL dy[] = {0,0,1,-1,0,0} ;
const LL dh[] = {0,0,0,0,1,-1} ;

const LL N = 105 ;
LL n , m , surface ;
LL A[N][N] ;
LL block[N][N][N] ;

signed main() {
	fre(surface) ;
	n = read() ;
	m = read() ;
	FOR(i,1,n)
		FOR(j,1,m)
			A[i][j] = read() ;
	FOR(i,1,n)
		FOR(j,1,m)
			FOR(h,1,A[i][j])
				block[i][j][h] = true ;
	FOR(i,1,n)
		FOR(j,1,m)
			FOR(h,1,A[i][j])
				FOR(o,0,5)
					if(!block[i+dx[o]][j+dy[o]][h+dh[o]]) ++surface ;
	return printf("%lld\n",surface),0 ;
}