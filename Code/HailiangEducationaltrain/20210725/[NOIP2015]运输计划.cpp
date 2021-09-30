#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std;

inline int read(register int x = 0, register bool f = false, register char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48); return f ? ~x + 1 : x;
}

const int maxlog = 30, N = 1e6 + 5;
int ans, n, m, k, u, v, w, tot, s;
int f[N][maxlog + 5], dep[N], c[N], sum[N], lg[N], dis[N], fr[N], to[N], dep2[N];
vector<pair<int, int> > G[N];

void dfs(int x, int fa)
{
	f[x][0] = fa;
	dep[x] = dep[fa] + 1;
	for (int i = 1; i <= lg[dep[x]]; ++i) f[x][i] = f[f[x][i - 1]][i - 1];
	for (auto v : G[x]) {
		int son = v.first;
		int w = v.second;
		if (son == fa) continue;
		dep2[son] = dep2[x] + w;
		dfs(son, x);
	}
}

int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	while (dep[x] > dep[y]) x = f[x][lg[dep[x] - dep[y]] - 1];
	if (x == y) return x;
	for (int i = lg[dep[x]] - 1; i >= 0; i--)
		if (f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	return f[x][0];
}

void dfs2(int x, int fa) {
	for (auto v : G[x]) {
		int son = v.first;
		if (son == fa) continue;
		dfs2(son, x);
		c[x] += c[son];
	} return;
}

bool check(int x) {
	memset(c, 0, sizeof c);
	int mx = 0; tot = 0;
	for (int i = 1; i <= m; ++i)
		if (dis[i] > x) {
			++tot, ++c[fr[i]], ++c[to[i]];
			c[lca(fr[i], to[i])] -= 2;
			mx = std::max(mx, dis[i] - x);
		}
	if (!tot) return true;
	dfs2(1, 0);
	//	for (int i = 1 ; i <= n ; ++i ) printf("%d%c",c[i],i != n ? ' ' : '\n' ) ;
	for (int i = 2; i <= n; ++i)
		if (c[i] == tot && dep2[i] - dep2[f[i][0]] >= mx) return true;
	return false;
}

signed main() {
	n = read(); m = read();
	for (int i = 1; i <= n; ++i) lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	for (int i = 1; i < n; ++i) u = read(), v = read(), w = read(), G[u].push_back(make_pair(v, w)), G[v].push_back(make_pair(u, w)), s += w;
	for (int i = 1; i <= m; ++i) fr[i] = read(), to[i] = read();
	dfs(1, 0);
	for (int i = 1; i <= m; ++i) dis[i] = dep2[fr[i]] + dep2[to[i]] - dep2[lca(fr[i], to[i])] * 2;
	//	for (int i = 1 ; i <= n ; ++i ) printf("%d%c",dep2[i],i != n ? ' ' : '\n' ) ;
	//	for (int i = 1 ; i <= m ; ++i ) printf("%d%c",dis[i],i != n ? ' ' : '\n' ) ;
	int l = 0, r = s;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	} printf("%d\n", l);
}
/*
5 5 5 4 4 1 5 5 1 4
*/