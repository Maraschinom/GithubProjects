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

const int N = 3e5 + 5;
int n, m, u, v, w, ans, cnt, tot, len;
int indeg[N], dfn[N], low[N], instack[N], bel[N], seq[N], path[N], lst[N];
stack<int> st;
vector<pair<int, int>> G[N], Graph[N];
vector<int> Circle[N];

void dfs(int x, int lst, int len) {
	for (auto y : G[x]) if (y.second > lst) {
		dfs(y.first, y.second, len + 1);
	} ans = max(ans, len);
}

void tarjian(int x, int lst) {
	dfn[x] = low[x] = ++cnt;
	instack[x] = true, st.push(x);
	for (auto y : G[x]) {
		int son = y.first;
		if (y.second <= lst) continue;
		if (!dfn[son]) tarjian(son, y.second), low[x] = min(low[x], low[son]);
		else if (instack[son]) low[x] = min(low[x], dfn[son]);
	} if (dfn[x] == low[x]) {
		++tot;
		while (st.top() != x) bel[st.top()] = tot, Circle[tot].push_back(st.top()), instack[st.top()] = false, st.pop();
		bel[st.top()] = tot, Circle[tot].push_back(st.top()), instack[st.top()] = false, st.pop();
	}
}

void Top_sort() {
	queue<int> q;
	for (int i = 1; i <= tot; ++i) if (!indeg[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		seq[++len] = u;
		for (auto v : Graph[u]) {
			int son = v.first;
			if (!(--indeg[son])) q.push(son);
		}
	}
}

signed main(int argc, char *argv[]) {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= m; ++i)
		u = read(), v = read(), w = read(), G[u].push_back(make_pair(v, w));
	if (n * n < 7e7) {
		for (int i = 1; i <= n; ++i) dfs(i, 0, 0);	
		return printf("%d\n", ans), 0;
	}
	for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjian(i, 0);
	for (int i = 1; i <= n; ++i) for (auto j : G[i]) if (bel[i] != bel[j.first])
		Graph[bel[i]].push_back(make_pair(bel[j.first], j.second)), ++indeg[bel[j.first]]; Top_sort();
	for (int i = len, res; i; --i) {
		path[seq[i]] = 0; res = 0;
		for (auto j : G[seq[i]]) {
			int son = j.first;
			if (j.second >= lst[son]) continue;
			if (path[son] > res) res = path[son], lst[seq[i]] = j.second;
		} ans = max(ans, path[seq[i]] = path[seq[i]] + res + (int)Circle[seq[i]].size());
	} return printf("%d\n", ans), 0;
}