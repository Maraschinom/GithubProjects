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
LL Q , l , r ;
LL cnt1 , cnt2 , cnt3 , cnt[26] , JC[N] ;

inline void cont (LL l,LL r) {
	cnt1 = cnt2 = cnt3 = 0 ;
	memset(cnt,0,sizeof cnt) ;
	FOR(i,l-1,r-1) {
		++ cnt[s[i]-'a'] ;
	}
	FOR(i,0,25) {
		cnt1 += cnt[i]&1 ;
		cnt3 += cnt[i]/2 ;
		cnt2 += cnt3 > 0 ;
	}
	cnt1 = std::max(cnt1,1ll) ;
	cnt2 = std::max(cnt3,1ll) ;
	printf("%lld\n",cnt1*JC[cnt3]%Mod) ;
}

signed main() {
	fre(palindromes) ;
	JC[0] = 1 ;
	FOR(i,1,N) JC[i] = (JC[i-1] * i) % Mod ;
	s = get() ;
	Q = read() ;
	FOR(i,1,Q) {
		l = read() ;
		r = read() ;
		cont(l,r) ;
	}
	return 0 ;
}