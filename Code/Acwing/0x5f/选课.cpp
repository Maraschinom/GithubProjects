#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 3e2 + 5;

int n, m, root, ans;
int fa[N], w[N];
int f[N][N];
vector<int> G[N];

void dfs(int x) {
	for (auto v : G[x])
		for (int i = m; ~i; --i)
			for (int j = i; ~j; --j)
				f[x][i] = max(f[x][i], f[x][i - j] + f[v][j]);
	if (x) for (int i = m; ~i; --i) f[x][i] = f[x][i - 1] + w[x];
}

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) 
		fa[i] = read(), w[i] = read();
	for (int i = 1; i <= n; ++i) {
		G[fa[i]].push_back(i);
	} dfs(0);
	return printf("%d\n", f[0][m]), 0;
}