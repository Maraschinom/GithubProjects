#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? ~x + 1 : x; 
} 

const int N = 1e4 + 5; 

int n, k, u, v, w, root, ans, tot;
int siz[N], mx[N], a[N], d[N], del[N];
vector<pair<int,int> > G[N];

void dfs(int x, int fa, int Size) {
	siz[x] = 1, mx[x] = 0;
	for (auto y : G[x]) {
		int son = y.first, w = y.second;
		if (son == fa || del[son]) continue;
		dfs(son, x, Size); siz[x] += siz[son];
		mx[x] = max(mx[x], siz[son]); 
	} mx[x] = max(mx[x], Size - siz[x]);
	if (mx[x] < mx[root]) root = x;
}

void dfs2(int x, int fa) {
	a[++ tot] = d[x];
	for (auto y : G[x]) {
		int son = y.first, w = y.second;
		if (son == fa || del[son]) continue;
		d[son] = d[x] + w;
		dfs2(son, x);
	}
} 

int calc(int x, int w) {
	tot = 0; d[x] = w; dfs2(x, 0);
	sort(a + 1, a + 1 + tot);
	int l = 1, r = tot, res = 0;
    while(l <= r) (a[l] + a[r] <= k) ? (res += r - l, ++ l) : (-- r);
	return res;
}

void solve(int x) {
	del[x] = true, ans += calc(x, 0);
	for (auto y : G[x]) {
		int son = y.first; if (del[son]) continue;
		ans -= calc(son, y.second); mx[root = 0] = n;
		dfs(son, x, siz[son]); solve(root);
	} 
}

signed main() {
	while((n = read()) | (k = read())) {
		memset(del, 0, sizeof del);
  		memset(siz, 0, sizeof siz);
		memset(mx, 0, sizeof mx);
		for (int i = 1; i <= n; ++i) G[i].clear();
		for (int i = 1; i < n; ++i) {
			u = read(), v = read(), w = read(),
			G[u].push_back(make_pair(v,w)),
			G[v].push_back(make_pair(u,w)); 
		}
		mx[root = 0] = n; dfs(1, 0, n);
		solve(root); printf("%d\n", ans);
	} return 0;
}
