#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 2e5 + 5, M = 1e6 + 5;

int n, k, root, son, ans = INT_MAX, tot, SIZE, u, v, w;
int mx[N], siz[N], anc[N], mn[M], dis[N], Edge[N];
bool del[N];
vector<PII> G[N];

#define x first
#define y second

void find(int u, int fa) {
	siz[u] = 1; mx[u] = 0;
	for (auto v : G[u]) {
		int son = v.x;
		if (del[son] || son == fa) continue;
		find(son, u); siz[u] += siz[son];
    	mx[u] = max(mx[u], siz[son]);
	}
	mx[u] = max(mx[u], SIZE - siz[u]);
	if (mx[u] < mx[root]) root = u;
}

void dfs(int u, int fa, int p, int dep) {
	if (p > k) return;
	dis[++ tot] = p; Edge[tot] = dep;
	for (auto v : G[u]) {
		int son = v.x;
		if (del[son = v.x] || son == fa) continue;
		dfs(son, u, p + v.y, dep + 1);
	}
}

void calc(int u) {
	mn[0] = tot = 0;
	for (auto v : G[u]) {
		int son = v.x;
		if (del[son]) continue;
		int cnt = tot;
		dfs(son, u, v.y, 1);
		for (int i = cnt + 1; i <= tot; ++i) 
			ans = min(ans, mn[k - dis[i]] + Edge[i]);
		for (int i = cnt + 1; i <= tot; ++i) 
			mn[dis[i]] = min(mn[dis[i]], Edge[i]);
	}
	for (int i = 1; i <= tot; ++i) mn[dis[i]] = 1e9;
}
	
void solve(int u) {
	del[u] = true; calc(u);
	for (auto v : G[u]) {
		int son = v.x;
		if (del[son]) continue;
		root = 0; SIZE = siz[son]; find(son, u); solve(root);
	}
}

signed main(int argc, char *argv[]) {
	n = read(), k = read();
	for (int i = 1; i <= n - 1; ++i)
		u = read() + 1, v = read() + 1, w = read(),
		G[u].push_back(make_pair(v,w)),
		G[v].push_back(make_pair(u,w));
	mx[root = 0] = (SIZE = n) + 1;
	memset(mn, 0x3f, sizeof mn); 
	SIZE = n, find(1, 0); solve(root);	
	return printf("%d\n", ans >= n ? -1 : ans), 0;
}