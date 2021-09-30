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
LL n , m , ans , Sum ;

struct city{
	LL p , x , sum ;
	city(){sum = p = 0 ; x = 1e15 ; }
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
}city[N],col[N];

bool vis[N] ;
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
	sort(col+1,col+1+n) ;
	FOR(i,1,m) {
		LL j = lower_bound(city+1,city+1+n,col[i])-city ;
		ROF(k,j,1) {
			if (col[i].x - city[k].x > col[i].p) break ;
			bel[k].push_back(i) ;
		}
		FOR(k,j+1,n) {
			if (city[k].x - col[i].x > col[i].p) break ;
			bel[k].push_back(i) ;
		}
	} 
	FOR(i,1,n) {
		if (bel[i].size() == 1) col[bel[i][0]].sum += city[i].p ;
		if (!bel[i].size()) Sum += city[i].p ;
	}
	FOR(i,1,m) {
		ans = std::max(ans,col[i].sum) ;
	}	
	printf("%lld\n",Sum+ans) ;
}