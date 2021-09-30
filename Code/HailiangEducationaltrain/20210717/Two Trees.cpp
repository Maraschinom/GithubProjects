#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

const int N = 1e5 + 5;
int n, fa;
int value[N];
vector<set<int>> G;

void dfs(int u) {
	while (G[u].size()) {
		int v = *G[u].begin();
		G[u].erase(v), G[v].erase(u);
		if (u + n == v) value[v] = -1;
		if (v + n == u) value[v] = 1;
		dfs(v);
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> fa;
		fa = !~fa ? 0 : fa;
		G[fa].insert(i), G[i].insert(fa);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> fa;
		fa = !~fa ? 0 : fa + n;
		G[fa].insert(i + n), G[i + n].insert(fa);
	}
	for (int i = 1; i <= n; ++i)
		if ((G[i].size() & 1) != (G[i + n].size() & 1))
			puts("IMPOSSIBLE");
	puts("POSSIBLE");
	for (int i = 1; i <= n; ++i)
		if (G[i].size() & 1)
			G[i].insert(i + n), G[i + n].insert(i);
	dfs(0);
	for (int i = 1; i <= n; ++i) printf("%d ", value[i]);
}