#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std;

typedef long long LL ;

inline LL read (register LL f = 0,register LL u = 0,register char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~ u + 1 : u ;
}

inline string get (register string s = "",register char ch = getchar()) {
	for(;ch < 'a' || ch > 'z';ch = getchar()) 0 ;
	for(;ch >= 'a' && ch <= 'z';ch = getchar()) s.push_back(ch) ; return s ;
}

static const LL N = 2e3 + 1e2 + 5 , Mod = 1e9 + 7 , M = 7e2 , inf = 2e9 + 1e8 ;
LL p , mn ;
LL c2 , c3 , c5 , c7 ;
LL Inv5 , Inv7 , inv5[N] , inv7[N] ;
LL Pow2[N] , Pow3[N] , Pow5[N] , Pow7[N] ;
LL digit[N] , use2 , use3 , use5 , use7 ;

unordered_map <LL,pair<LL,LL>> f ;

inline LL qpow(LL x,LL y) {
	LL ans = 1 ; for (;y;y>>=1,x=(x*x)%Mod) if(y&1) ans = (ans*x) % Mod ; return ans ;
}

inline void Prepare() {
	Inv5 = qpow(5,Mod-2) , Inv7 = qpow(7,Mod-2) ;
	Pow2[0] = Pow3[0] = Pow5[0] = Pow7[0] = inv5[0] = inv7[0] = 1 ;
	for (register LL i = 1 ; i <= N ; ++i ) {
		Pow2[i] = ( Pow2[i-1] * 2 ) % Mod ; Pow3[i] = ( Pow3[i-1] * 3 ) % Mod ; 
		Pow5[i] = ( Pow5[i-1] * 5 ) % Mod ; Pow7[i] = ( Pow7[i-1] * 7 ) % Mod ;
		inv5[i] = inv5[i-1] * Inv5 % Mod ; inv7[i] = inv7[i-1] * Inv7 % Mod ;
	}
	for (register LL i = 0 ; i <= 2100 ; ++i ) for (register LL j = 0 ; j <= 1400 && i/3 + j/2 <= 700 ; ++j ) 
		f[Pow2[i]*Pow3[j]%Mod] = make_pair(i,j) ;
}

inline LL Rec() {
	digit[9] = digit[3] / 2 , digit[8] = digit[2] / 3 ;
	digit[3] %= 2 , digit[2] %= 3 ;
	digit[6] = min (digit[2],digit[3]) ;
	digit[2] -= digit[6] , digit[3] -= digit[6] ;
	if (digit[2] == 2) digit[4] = 1 , digit[2] = 0 ;
	return digit[2] + digit[3] + digit[4] + digit[5] + digit[6] + digit[7] + digit[8] + digit[9] ;
}

signed main() {
	Prepare() ;
	for (register LL T = read() ; T ; --T ) {
		p = read() ;
		if (!p) { puts("10") ; continue ; }
		if (p == 1) { puts("1") ; continue ; } 
		mn = inf ;
		for (register LL p1 = 0 ; p1 <= M ; ++p1 )
			for (register LL p2 = 0 ; p2 + p1 <= M ; ++p2 ) {
				LL val = inv5[p1] * inv7[p2] % Mod * p % Mod ;
				if (f.count(val)) {
					digit[2] = f[val].first , digit[3] = f[val].second , digit[5] = p1 , digit[7] = p2 ; 
					digit[4] = 0 ; 
					LL Size = Rec() ; 
					if (Size < mn) mn = Size , use2 = f[val].first , use3 = f[val].second , use5 = p1 , use7 = p2 ;
				}
			} digit[4] = 0 ;
		digit[2] = use2 , digit[3] = use3 , digit[5] = use5 , digit[7] = use7 ;
		digit[9] = digit[3] / 2 , digit[8] = digit[2] / 3 ;
		digit[3] %= 2 , digit[2] %= 3 ;
		digit[6] = min (digit[2],digit[3]) ;
		digit[2] -= digit[6] , digit[3] -= digit[6] ;
		if (digit[2] == 2) digit[4] = 1 , digit[2] = 0 ;
		for (register LL i = 2 ; i <= 9 ; ++i ) for (register LL j = 1 ; j <= digit[i] ; ++j ) printf("%lld",i) ; puts("") ;
	}
    return 0 ;
}
