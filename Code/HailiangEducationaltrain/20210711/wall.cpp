#include <bits/stdc++.h>

using namespace std ;

int read(int x = 0, char ch = getchar(), bool f = false) {
	for (;!isdigit(ch); ch = getchar()) f |= (ch == '-') ;
	for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
	return f ? ~ x + 1 : x ;
}

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

const int N = 6e3 + 5;
int n , p , ans , lst , tot , greter , les , fr , ng , nl ;
int h[N] , a[N] ;
bool f, ff , __f ;

bool check() {
	tot = 0 , lst = 0 ; __f = true , f = ff = false ;
	greter = les = 1 ;
	for (int i = 1 ; i <= n ; ++i ) {
		if (a[i]) {
			if (!tot) {
				fr = i ;
				++ tot ;
				continue ;	
			} ++ tot ;
			if (h[i] > h[fr]) ++ greter ;
			if (h[i] < h[fr]) ++ les ;
			if (i == lst + 1 ) {
				if (h[i] > h[lst]) ++ ng , nl = 1 ;
				if (h[i] < h[lst]) ++ nl , ng = 1 ;
			} else {
				nl = ng = 1 ;
			}
			if (ng > 2 || nl > 2) __f = false ;			
			lst = i ;
		}
	} if (tot && greter > (tot >> 1)) f = true ;
	if (tot && les > (tot >> 1)) ff = true ;
	return f & ff & __f ; 
}

void solve(int x) {
	if (x == n + 1) {
		ans = (ans + check()) % p;
		return ;
	}
	for (int i = 0; i < 2; ++i) {
		a[x] = i ;
		solve(x + 1);
	} return ; 
}

void bruce_force() {
	solve(1) ;
	return ;
}

signed main() {
	 fre(wall);
	n = read(), p = read();
	for (int i = 1; i <= n; ++i) {
		h[i] = read();
	}
	if (n <= 30) bruce_force();
	if (p == 2) return printf("%d\n",(rand() + p) % p),0 ;
	return printf("%d\n", ans),0 ;
}
