#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? ~x + 1 : x;
}

const int N = 1e5 + 5;

int n, mx, Son, sum;
int son[N], siz[N], cnt[N], ans[N], a[N];
vector<int> G[N];

void dfs(int x, int pre) {
	siz[x] = 1;
	for (auto v : G[x]) if (v != pre){
		dfs(v, x); siz[x] += siz[v];
		if (siz[v] > siz[son[x]]) son[x] = v;
	}
}

void add(int x, int pre, int val) {
	cnt[a[x]] += val;
	if (cnt[a[x]] > mx) mx = cnt[a[x]], sum = a[x];
	else if (cnt[a[x]] == mx) sum += a[x];
	for (auto v : G[x]) if (v != pre && v != Son)
		add(v, x, val);
}

void dfs2(int x,int pre,int opt) {
	for (auto v : G[x]) if (v != pre && v != son[x])
		dfs2(v, x, 0);
	if (son[x]) dfs2(son[x], x, 1), Son = son[x];
	add(x, pre, 1), ans[x] = sum, Son = 0;
	if (!opt) add(x, pre, -1), sum = 0, mx = 0;
}

signed main() {
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1, u, v; i < n; ++i) {
		u = read(), v = read();
		G[u].emplace_back(v); G[v].emplace_back(u);
	} dfs(1, 0), dfs2(1, 0, 0);
	for (int i = 1; i <= n; ++i) printf("%d ",ans[i]);
}
	for (int i = 1, u, v; i < n; ++i) {
		u = read(), v = read();
		G[u].emplace_back(v); G[v].emplace_back(u);
	} dfs(1, 0), dfs2(1, 0, 0);
	for (int i = 1; i <= n; ++i) printf("%d ",ans[i]);
}
