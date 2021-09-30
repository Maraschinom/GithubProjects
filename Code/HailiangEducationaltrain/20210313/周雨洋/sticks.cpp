// #pragma GCC diagnostic error "-std=c++11"
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cctype>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<cstring>

using namespace std;

#define re register

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

#define inl inline 

typedef long long LL ;
typedef pair<LL,LL> PLL ;

inline LL read (re LL f = 0,re LL u = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~u + 1 : u ;
}

static const LL N = 1e5+5 ;
LL n , f[N] , a[N] , ans , Max ;
map<LL,LL> val ;

inline LL calc(LL x){
	if (x == 1) return 1 ;
	LL res = 1 , pos = 0, se = 0 ;
	for (LL i = 2 ; i * i <= x ; ++i ) {
		if (x%i) continue ;
		if (val.find(i) == val.end() ) pos = calc(i) ;
		else pos = val[i] ;
		if (val.find(x/i) == val.end() ) se = calc(x/i) ;
		else se = val[x/i] ;
		res = std::max(res,std::max(pos*(x/i),se*i)+1) ;
	} return val[x] = std::max(res,x+1) ;
}	

signed main(int argv,char *argc[]){
	fre(sticks) ;
	n = read() ;
	for (LL i = 1 ; i <= n ; ++i ) a[i] = read() , Max = std::max(Max,a[i]) ;
	if (Max < N){
		f[1] = 1 ;	
		for (LL i = 2 ; i <= Max ; ++i ) {
			f[i] = 1 ;
			for (LL j = 1 ; j*j <= i ; ++j ) {
				if (i%j) continue ;
				f[i] = std::max(f[i],std::max(f[j]*(i/j)+1,f[i/j]*j+1)) ;
			}
		}
		for (LL i = 1 ; i <= n ; ++i ) ans += f[a[i]] ;
	} else {
		for (LL i = 1 ; i <= n ; ++i ) {
			if (val.find(a[i]) == val.end()) ans += calc(a[i]) ;
			else ans += val[a[i]] ;
		}
	}
	printf ("%lld\n",ans) ;
	return 0 ;
}