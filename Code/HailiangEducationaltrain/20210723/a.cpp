#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

namespace io{
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using io::read;

constexpr int N = 5e4 + 5;
int n, u, v, ans;
int value[N], f[N];
vector<int> G[N];

void build(int u, int pre) {
	f[u] = pre;
	for (auto v : G[u]) {
		if (v == pre) continue;
		build(v, u);
	}
}

void dfs(int u, int fa, int sum, int len, int minn) {
	ans = max(ans, sum);
	for (auto v : G[u]) {
		if (v == fa) continue;
		int s = min(value[v], minn) * (len + 1);
		dfs(v, u, s, len + 1, min(value[v], minn));
	}
}

#define fre(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout);

signed main(int argc,char *argv[]) {
	fre(a); n = read();
	for (int i = 1; i <= n; ++i) value[i] = read();
	for (int i = 1; i < n; ++i) {
		u = read(), v = read();
		G[u].emplace_back(v), G[v].emplace_back(u);
	} build(1,-1);
	for (int i = 1; i <= n; ++i)
		dfs(i, f[i], 1, 1, value[i]);
	return printf("%d\n", ans), 0;
}