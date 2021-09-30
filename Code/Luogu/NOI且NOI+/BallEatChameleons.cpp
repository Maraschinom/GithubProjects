#pragma GCC diagnostic error "-std=c++11"
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
#define close() fclose(stdin),fclose(stdout);
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

const LL N = 5e5+5 , Mod = 998244353 ;
LL sum , n , k ;
LL inv[N] , fac[N] ;

inline LL Calc(LL n,LL m) {
	return n >= m ? fac[n] * inv[m] % Mod * inv[n-m] % Mod : 0 ;
}

signed main(int argv,char *argc[]) {
	n = read() , k = read() ; fac[0] = fac[1] = inv[0] = inv[1] = 1 ;
	FOR(i,2,k) fac[i] = (fac[i-1] * i) % Mod , inv[i] = (inv[Mod%i] * (Mod-Mod/i)) % Mod ;
	FOR(i,2,k) inv[i] = (inv[i-1] * inv[i]) % Mod ;
	FOR(i,n,k) sum = (sum+Calc(k-1,i-1)) % Mod ;
	printf("%lld\n",sum) ;
	close() ; 
}