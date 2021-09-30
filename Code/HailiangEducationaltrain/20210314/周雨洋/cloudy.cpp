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

const LL N = 2e5 + 10 ;
LL n , m , ans , Sum , res ;
LL l[N] , r[N] , sum[N] , vis[N] , P[N] ;

struct city{
	LL p , x ;
	city(){p = 0 ; x = 1e15 ; }
	friend bool operator < (const city a,const city b) {
		return a.x < b.x ;
	}
	friend bool operator == (const city a,const city b) {
		return a.x == b.x ;
	}
	friend bool operator > (const city a,const city b) {
		return a.x > b.x ;
	}
	friend bool operator <= (const city a,const city b) {
		return a.x <= b.x ;
	}
	friend bool operator >= (const city a,const city b) {
		return a.x >= b.x ;
	}
	friend LL operator - (const city a,const LL b) {
		return a.x - b ;
	}
	friend LL operator + (const city a,const LL b) {
		return a.x + b ;
	}
}city[N],col[N];

vector<LL> bel[N] ;

signed main() {
	fre(cloudy) ;
	n = read() ;
	FOR(i,1,n) city[i].p = read() ;
	FOR(i,1,n) city[i].x = read() ;
	m = read() ;
	FOR(i,1,m) col[i].x = read() ;
	FOR(i,1,m) col[i].p = read() ;
	sort(city+1,city+1+n) ;
	FOR(i,1,n) P[i] = city[i].x ;
	FOR(i,1,m) {
		l[i] = lower_bound(P+1,P+1+n,col[i]-col[i].p) - P ;
		r[i] = upper_bound(P+1,P+1+n,col[i]+col[i].p) - P - 1 ;
		++vis[l[i]] , --vis[r[i]+1] ;
	}
	for (LL i = 1 , s = vis[1] ; i <= n ; s += vis[++i] ) {
		if (!s) res += city[i].p ; sum[i] = sum[i-1] ;
		if (s==1) sum[i] += city[i].p ;
	}
	for (LL i = 1 ; i <= m ; ++i ) ans = std::max(ans,sum[r[i]]-sum[l[i]-1]) ;
	return printf("%lld\n",ans+res) , 0 ;
}
