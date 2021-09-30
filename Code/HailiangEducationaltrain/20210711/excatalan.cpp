#include <bits/stdc++.h>

using namespace std ;

int read(int x = 0,char ch = getchar(),bool f = false) {
	for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
	for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
	return f ? ~ x + 1 : x ;
}

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define mul(x,y) ((1LL * x * y) % mod)
#define add(x,y) ((x + y) % mod)

const int N = 1e6 + 5 , mod = 998244353 ;

int n , m , ans , tot ;
int fact[N] , a[N << 1] ;
stack<int> l,r ;
bool f ;

int qpow(int x,int y) {
	int ans = 1 ;
	x %= mod , y %= mod ;
	for (;y;y >>= 1,x = mul(x,x)) if (y&1) ans = mul(ans,x) ;
	return ans ;
}

bool check() {
	while(l.size()) l.pop() ;
	while(r.size()) r.pop() ;
	for (int i = 1; i <= 2 * n ; ++i ) {
		if(a[i]) {
			l.push(i) ;
		} else {
			r.push(i) ;
			if(l.size() && r.size()) r.pop() , l.pop() ;
		}
	} return r.size() + l.size() == 2 * m ;
}

void solve(int x) {
	if (x == 2 * n + 1) {
		ans += check() ;
		return ;
	}
	if (n + 1 + tot <= x) f = true ;
	else f = false ;
	for (int i = 0 + f ; i < 2 - (int)(tot == n); ++i ) {
		a[x] = i ;
		if (i == 1) ++ tot ;
		solve(x + 1) ;
		if (i == 1) -- tot ;
	} return ;
}

int bruce_force() {
	solve(1) ;
	return ans ;
}

signed main() {
	fre(excatalan);
	n = read() , m = read() ;
	if (m == 0) {
		ans = 1 ;
		for (int i = n + 1 ; i <= (n << 1) ; ++i ) ans = mul(ans,i) ;
		for (int i = 1 ; i <= n ; ++i ) ans = mul(ans,qpow(i,mod - 2)) ;
		return printf("%d\n",ans),0 ;
	}
	return printf("%d\n",bruce_force()),0 ;
}
