//神经细胞 全面戒备 
#include <bits/stdc++.h>

using namespace std ;

int read(int x = 0 ,char ch = getchar(),bool f = false) {
	for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
	for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
	return f ? ~ x + 1 : x ;
}

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

const int N = 2e3 + 5 , mod = 1e9 + 7 ;
int tot , n , ans ;
int a[N] , l[N] , r[N] ;
bool vis[N] ;

bool Edge(int x,int y) {
	if (l[x] >= l[y]) swap(x,y) ;
	return r[x] >= l[y] ;
}

int dfs(int x,int pre) {
	int siz = 1 ;
	vis[x] = true ;
	for (int i = 1 ; i <= n ; ++i ) {
		if (a[i]) {
			if (i == pre || i == x) continue ;
			if (vis[i] && Edge(x,i)) return -1e9 ;
			if (vis[i]) continue ;
			if (Edge(x,i)) siz += dfs(i,x) ;
		}
	} return siz ;
}

bool check() {
	for (int i = 1 ; i <= n ; ++i ) {
		if (a[i]) {
			int x = dfs(i,i) ;
			return x == tot ;	
		}
	}
}

void solve(int x) {
	if (x == n + 1) {
		if (!tot) return ;
		for (int i = 1 ; i <= n ; ++i ) vis[i] = false ;
		ans += check() ;
		return ; 
	}
	for (int i = 0 ; i < 2; ++i ) {
		a[x] = i ;
		if (a[x]) ++ tot ;
		solve(x + 1) ;
		if (a[x]) -- tot ;
	} return ;
}

signed main() {
	fre(b) ; 
	n = read() ;
	for (int i = 1 ; i <= n ; ++i ) l[i] = read() , r[i] = read() ;
	solve(1) ;
	return printf("%d\n",ans % mod),0 ;
}
