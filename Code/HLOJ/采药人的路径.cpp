#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 1e6 + 5;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? ~x + 1 : x; 
}

int n, root, maxdep, u, v, w, sum;
int siz[N], mx[N], dep[N], cnt[N];
LL f[N][2], g[N][2], ans, dis[N];
bool del[N];
vector<PII> G[N];

void dfs(int x, int fa) {
	siz[x] = 1, mx[x] = 0;
	for (auto y : G[x]) {
		int son = y.first, w = y.second;
		if (son == fa || del[son]) continue;
		dfs(son, x); siz[x] += siz[son];
		mx[x] = max(mx[x], siz[son]); 
	} mx[x] = max(mx[x], sum - siz[x]);
	if (mx[x] < mx[root]) root = x;
}

void dfs2(int x, int fa) {
	maxdep = max(maxdep, dep[x]);
	++ f[dis[x]][cnt[dis[x]] > 0];
	++ cnt[dis[x]];
	for (auto v : G[x]) {
		int son = v.first;
		if (del[son] || son == fa) continue;
		dis[son] = dis[x] + v.second;
		dep[son] = dep[x] + 1;
		dfs2(son, x);
	}
	-- cnt[dis[x]]; 
}

inline void solve(int x) {
	int maxx = 0; del[x] = true; g[n][0] = 1;
	for (auto v : G[x]) {
		int son = v.first;
		if (del[son]) continue;
		dis[son] = n + v.second;
		dep[son] = maxdep = 1;
		dfs2(son, 0);
		maxx = max(maxx, maxdep);
 		ans += (g[n][0] - 1) * f[n][0];
	 	for (int j = -maxdep; j <= maxdep; ++j)
	 		ans += g[n - j][1] * f[n + j][1] + g[n- j][1] * f[n + j][0] + g[n - j][0] * f[n + j][1];
	 	for (int i = n - maxx; i <= n + maxx; ++i)
			for (int j = n - maxdep; j <= n + maxdep; ++j)
			g[j][0] += f[j][0], g[j][1] += f[j][1], f[j][0] = f[j][1] = 0;
 	}
    for (int i = n - maxx; i <= n + maxx; ++i)
        g[i][0] = g[i][1] = 0;
    for (auto v : G[x]) {
    	int son = v.first;
		if (del[son]) continue;
		sum = siz[son], root = 0;
		dfs(son, 0), solve(root);
    }
}

signed main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	n = read();
	for (int i = 1; i < n; ++i) {
		u = read(), v = read(), w = read();
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
	} mx[root = 0] = sum = n;
	dfs(1, 0); solve(root);
	return printf("%lld\n", ans), 0;
}
