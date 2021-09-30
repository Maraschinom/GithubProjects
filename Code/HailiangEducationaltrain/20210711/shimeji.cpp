#include <bits/stdc++.h>

using namespace std ;

int read(int x = 0,char ch = getchar(),bool f = false) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 1e6 + 5 , mod = 998244353 ;

typedef long long LL ;
typedef pair<int,int> PII ;
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define add(x,y) ((x + y) % mod)
#define mul(x,y) ((1LL * x * y) % mod)

int n , ans ;
int s[N] , t[N] , a[N] ;
bool vis[N] ;
vector<PII> tr[N] ;

int qpow(int x,int y) {
	int ans = 1 ; 
	x %= mod , y %= mod ; 
	for (;y;y >>= 1,x = mul(x,x)) if (y&1) ans = mul(ans,x) ;
	return ans ;
} 

int dfs(int x,int pre) {
    vis[x] = true ; int Size = 1 ;
    for (int i = 0 ; i < tr[x].size() ; ++ i) {
        if (a[tr[x][i].second]) {
            int v = tr[x][i].first ;
            if (v == pre) continue ;
            Size += dfs(v,x) ;
        }
    } return Size ;
}

int calc() {
    int ans = 1 ;
    for (int i = 1 ; i <= n ; ++ i) vis[i] = false ;
    for (int i = 1 ; i <= n ; ++ i) { 
        if (!vis[i]) ans = mul(ans,dfs(i,-1)) ;
    } return ans ;
}

void spawn(int x) {
    if (x == n + 1) {
		ans = add(ans,calc()) ;
    	return ;
	}
    for (int i = 0 ; i < 2 ; ++ i) {
        a[x] = i ;
        spawn(x + 1) ;
    }
	return ;
}

signed main() {
	// fre(shimeji) ;
    n = read() ;
    for (int i = 1 ; i < n ; ++ i) {
        s[i] = read() , t[i] = read() ;
        tr[s[i]].push_back(make_pair(t[i],i)) ; tr[t[i]].push_back(make_pair(s[i],i)) ;
    } spawn(1) ;
    return printf("%lld\n",(1LL * ans * qpow(qpow(2,n),mod - 2)) % mod),0 ;
}
