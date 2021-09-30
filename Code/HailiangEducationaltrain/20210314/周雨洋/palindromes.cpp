// #pragma GCC diagnostic error "-std=c++11"
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bits/stdc++.h>

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

inline string get (re string s = "",re char ch = getchar()) {
	for(;ch < 'a' || ch > 'z';ch = getchar()) 0 ;
	for(;ch >= 'a' && ch <= 'z';ch = getchar()) s.push_back(ch) ; return s ;
}

string s ;

const LL N = 1e5+5 , Mod = 1e9+7 ;
LL Q , l , r , ans ;
LL cnt1 , cnt2 , cnt[N][26] , fac[N] , inv[N] , a[N];

inline LL fast_pow (LL x,LL y){
	LL ans = 1 ; for(;y;y>>=1,x=(x*x)%Mod) if(y&1) ans=(ans*x)%Mod ; return ans ;
}

inline void solve (LL l,LL r) {
	cnt1 = cnt2 = 0 ;
	FOR(i,0,25) {
		a[i] = cnt[r][i] - cnt[l-1][i] ;
		cnt1 += a[i]&1 ;
//		cout << a[i] << endl ;
		a[i] >>= 1 ;
		cnt2 += a[i] ;
	}
	ans = fac[cnt2] * std::max(1ll,cnt1) % Mod ;
//	cout << ' ' << fac[cnt2] ;
	FOR(i,0,25) ans = ans*inv[a[i]]%Mod ;
	printf("%lld\n",ans) ; 
}

signed main() {
	fre(palindromes) ;
	fac[0] = 1 ;
	FOR(i,1,N) fac[i] = (fac[i-1] * i) % Mod ;
	inv[N-1] = fast_pow(fac[N-1],Mod-2) ;
	ROF(i,N-2,0) inv[i] = inv[i+1]*(i+1)%Mod ;
	s = get() ;
	s = " " + s ;
	FOR(i,1,s.length()-1) {
		FOR(j,0,25) cnt[i][j] = cnt[i-1][j] ;
		++ cnt[i][s[i]-'a'] ;
	}
	Q = read() ;
//	printf("%lld\n",inv[0]) ;
	FOR(i,1,Q) {
		l = read() ;
		r = read() ;
		solve (l,r) ;
	}
	return 0 ;
}
