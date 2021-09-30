#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 105;
 
int n, V, root;
int v[N], w[N], f[N];
int g[N][N];
vector<int> G[N];

void dfs(int x) {
	for (int i = v[x]; i <= V; ++i) g[x][i] = w[x];
	for (auto y : G[x]) {
		dfs(y);
		for (int i = v; i >= v[x]; --i)
			for (int j = 0; j <= i - v[x]; ++j)
				g[x][i] = max(g[x][i], g[x][i - j] + g[y][j]);
	} return;
}

signed main() {
	n = read(), V = read();
	for (int i = 1; i <= n; ++i) {
		v[i] = read(), w[i] = read(), f[i] = read();
		if (f[i] != -1) G[f[i]].push_back(i);
		else root = i;
	} dfs(root); 
	return printf("%d\n", g[root][V]), 0;
}