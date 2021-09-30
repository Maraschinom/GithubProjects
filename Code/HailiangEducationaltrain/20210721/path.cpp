#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

namespace io {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using io::read;

const int N = 5e2 + 5;
int n, m, u, v, w;
int a[N], id[N];
long long path[N][N], ans[N][N];

bool compare(int x, int y) {
	return a[x] < a[y];
}

signed main() {
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read(), id[i] = i;
	sort(id + 1, id + 1 + n, compare);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i == j) ans[i][j] = path[i][j] = 0;
			else ans[i][j] = 2e18, path[i][j] = 1e9;
	for (int i = 1; i <= m; ++i)
		u = read(), v = read(), w = read(),
		path[u][v] = path[v][u] = w, ans[u][v] = ans[v][u] = w * max(a[u],a[v]);
	for (int _ = 1; _ <= n; ++_) {
		int k = id[_];
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (path[i][j] > max(path[i][k], path[k][j]))
					path[i][j] = max(path[i][k], path[k][j]),
					ans[i][j] = min(ans[i][j], path[i][j] * max(max(a[i],a[j]),a[k]));
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			printf("%lld%c", ans[i][j], j == n ? '\n' : ' '); return 0;
}