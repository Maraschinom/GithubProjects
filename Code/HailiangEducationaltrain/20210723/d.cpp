#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <unordered_map>
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

constexpr int N = 1e5 + 5;
int ans, n, m, l, r, x, u, v, w;
vector<pair<int,int>> G[N];

void dfs(int x, int pre, int dep) {
	if (l <= x && x <= r) ans = min(ans, dep);
	for (auto v : G[x]) {
		int son = v.first;
		if (son == pre) continue;
		dfs(son,x,dep + v.second);
	}
}

signed main() {
	fre(d); n = read();
	for (int i = 1; i < n; ++i) {
		u = read(), v = read(), w = read();
		G[u].emplace_back(make_pair(v, w));
		G[v].emplace_back(make_pair(u, w));
	} m = read();
	for (int i = 1; i <= m; ++i) {
		l = read(), r = read(), x = read();
		ans = 1e9 + 7; dfs(x, -1, 0); printf("%d\n", ans);
	} return 0;
}