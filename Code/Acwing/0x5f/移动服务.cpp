#include <bits/stdc++.h>

using namespace std;;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 2e2 + 5, M = 1e3 + 5, inf = 2147483647;

int l, n, ans = inf;
int p[M];
int cost[N][N];
int f[M][N][N];

signed main() {
	l = read(), n = read();
	for (int i = 1; i <= l; ++i)
		for (int j = 1; j <= l; ++j) cost[i][j] = read();
	for (int i = 1; i <= n; ++i) p[i] = read(); p[0] = 3;
	memset(f, 0x3f, sizeof f); f[0][1][2] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 1; j <= l; ++j)
			for (int k = 1; k <= l; ++k) {
				if (j == k || j == p[i] || k == p[i]) continue;
				f[i + 1][j][k] = min(f[i + 1][j][k], f[i][j][k] + cost[p[i]][p[i + 1]]);
				f[i + 1][p[i]][k] = min(f[i + 1][p[i]][k], f[i][j][k] + cost[j][p[i + 1]]);
				f[i + 1][j][p[i]] = min(f[i + 1][j][p[i]], f[i][j][k] + cost[k][p[i + 1]]);
			}
	for (int i = 1; i <= l; ++i)
		for (int j = 1; j <= l; ++j) {
			if (i == j || i == p[n] || j == p[n]) continue;
			ans = min(ans, f[n][i][j]);
	}
	return printf("%d\n", ans), 0;
}