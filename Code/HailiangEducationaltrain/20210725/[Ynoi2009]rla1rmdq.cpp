#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? ~x + 1 : x;
}

const int N = 2e5 + 5;
int n, m, l, r, u, v, w, rt, opt;
int dep[N], anc[N], a[N];
vector<PII> G[N];

void dfs(int x, int pre) {
	for (auto v : G[x]) if (v.first ^ pre){
		anc[v.first] = x;
		dep[v.first] = dep[x] + v.second;
		dfs(v.first, x);
	} return;
}

signed main() {
	n = read(); m = read(); rt = read();
	for (int i = 1; i < n; ++i) {
		u = read(), v = read(), w = read();
		G[u].push_back(make_pair(v,w)),
		G[v].push_back(make_pair(u,w));
	}
	for (int i = 1; i <= n; ++i) a[i] = read();
	dfs(rt ,0); anc[rt] = rt; dep[rt] = 0;
	for (int i = 1; i <= m; ++i) {
		opt = read();
		if (opt & 1) {
			l = read(), r = read();
			for (int j = l; j <= r; ++j) a[j] = anc[a[j]];
		} else {
			l = read(), r = read();
			int ans = 1e9 + 7;
			for (int j = l; j <= r; ++j) ans = min(dep[a[j]], ans);
			printf("%d\n",ans);
		}
	}
}
