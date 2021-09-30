//拉长耳朵 提高警惕 
#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

#define fre(x) freopen(#x".in","r",stdin) ;freopen(#x".out","w",stdout) ;
typedef pair<int, int> PII;

const int N = 2e3 + 5;

int n, k, u, v, w, ans, idx;
int c[N];
bool vis[N] ;
vector<PII> G[N];
vector<int> Find;

int dfs(int x,int pre,int dep,int color) {
	int ans = 0 ;
	for (PII v:G[x]) {
		if (v.first == pre) continue ;
		if (c[v.first] == color) ans += dep + v.second ;
		ans += dfs(v.first,x,dep + v.second,color) ;
	}
	return ans ;
}

signed main() {
	fre(a);
	n = read(); k = read();
	for (int i = 1; i < n; ++i) {
		u = read(), v = read(); w = read();
		G[u].push_back(make_pair(v,w)), G[v].push_back(make_pair(u,w));
	}
	for (int i = 1 ; i <= n ; ++i ) Find.push_back(i) , c[i] = 1;
	for (int i = 1 ; i <= n ; ++i ) {
		ans += dfs(i,-1,0,1) ;
	} ans >>= 1 ;
	for (int i = 1 ; i <= k ; ++i ) {
		int res = -1e9 ;
		for (int j = 1 ; j <= n ; ++j ) {
			if (vis[j]) continue ;
			int x = dfs(j,-1,0,0) - dfs(j,-1,0,1) ;
			if (res < x) res = x , idx = j ;
		} 
		vis[idx] = true , c[idx] = 0 , ans += res ;
	}
	return printf("%d\n",ans) , 0 ; 
}
