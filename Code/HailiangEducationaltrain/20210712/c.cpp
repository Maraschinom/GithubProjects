// ring~ ring~ ring~ °®µÄºÍÏÒÁå~ 

#include <bits/stdc++.h>

using namespace std ;

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

int read(int x = 0,char ch = getchar(),bool f = false) {
	for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
	for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
	return f ? ~ x + 1 : x ; 
}

const int N = 3e2 + 5 ;
int n , m , x , ans ;
deque<int> seq[N] ;
int arr[N * N] ;

bool check(int l,int r) {
	int len = 1 ;
	for (int i = 2 ; i <= (r - l + 1) * n ; ++i ) {
		if (arr[i] == arr[i - 1]) ++ len ;
		else len = 1 ;
		if (len >= (r - l + 1)) return false ;
	} return true ;
}

void solve(int x,int l,int r) {
	if (x == n * (r - l + 1) + 1) {
		ans += check(l,r) ;
		return ;
	}
	for (int i = l ; i <= r ; ++i ) {
		if (!seq[i].size()) continue ;
		arr[x] = seq[i].front() ; 
		seq[i].pop_front() ;
		solve(x + 1,l,r) ;
		seq[i].push_front(arr[x]) ; 
	}
}

signed main() {
	fre(c) ;
	m = read() , n = read() ;
	for (int i = 1 ; i <= m ; ++i ) 
		for (int j = 1 ; j <= n ; ++j ) x = read() ,seq[i].push_back(x) ; 
	for (int i = 1 ; i <= m ; ++i )
		for (int j = i + 1 ; j <= m ; ++j ) {
			solve(1,i,j) ;
		} return printf("%d\n",ans),0 ;
} 
