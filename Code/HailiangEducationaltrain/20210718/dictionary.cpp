#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <queue>

using namespace std;

namespace Read {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using Read::read;

typedef pair<int, int> PII;

const int N = 1e5 + 5;
int n, m, cnt;
int a[N], b[N], bel[N], dep[N];
int indeg[N];
vector<int> G[N], Graph[N];
bool vis[N], vis2[N];
bool has_none_circle = true;

void dfs(int x) {
	vis[x] = true;
	vis2[x] = true;
	bel[x] = cnt;
	Graph[cnt].push_back(x);
	for (int y : G[x]) {
		if (vis[y]) return has_none_circle = false, void();
		dep[y] = dep[x] + 1;
		dfs(y);
	}
	vis[x] = false;
}

void Top_sort(int idx) {
	priority_queue<PII, vector<PII>, greater<PII> > Q;
	for (int v : Graph[idx]) if (!indeg[v]) Q.push(make_pair(dep[v], v));
	while (!Q.empty()) {
		int u = Q.top().second; Q.pop();
		printf("%d ", u);
		for (int v : G[u]) {
			if (!(--indeg[v])) Q.push(make_pair(dep[v], v));
		}
	} return;
}

#define fre(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout) ;

signed main() {
	fre(dictionary); n = read(), m = read();
	for (int i = 1; i <= m; ++i) {
		a[i] = read(), b[i] = read();
		G[a[i]].push_back(b[i]); ++indeg[b[i]];
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis2[i]) ++cnt, dfs(i);
	}
	if (!has_none_circle) return puts("-1"), 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[bel[i]]) {
			Top_sort(bel[i]);
			vis[bel[i]] = true;
		}
	}
	return 0;
}
