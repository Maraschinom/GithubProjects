#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

namespace io {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using namespace io;

const int N = 1e6 + 5;

int n, m, cnt, tot, u, v, a, b;
int dfn[N], low[N], bel[N];
bool instack[N];
stack<int> st;
vector<int> G[N << 1];

void Tarjan(int u) {
	dfn[u] = low[u] = ++cnt;
	instack[u] = true, st.push(u);
	for (auto son : G[u]) {
		if (!dfn[son]) Tarjan(son), low[u] = min(low[u], low[son]);
		else if (instack[son]) low[u] = min(low[u], dfn[son]);
	} if (dfn[u] == low[u]) {
		++tot; while (st.top() != u) bel[st.top()] = tot, instack[st.top()] = false, st.pop();
		bel[st.top()] = tot, instack[st.top()] = false, st.pop();
	}
}

void add(int x, int y) {
	G[x].push_back(y);
}

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= m; ++i) {
		u = read(), a = read(), v = read(), b = read();
		if (a & b) add(u + n, v), add(v + n, u);
		if (!a && b) add(u, v), add(v + n, u + n);
		if (a && !b) add(u + n, v + n), add(v, u);
		if (!a && !b) add(u, v + n), add(v, u + n);
	}
	for (int i = 1; i <= 2 * n; ++i)
		if (!dfn[i]) Tarjan(i);
	for (int i = 1; i <= n; ++i) {
		if (bel[i] == bel[i + n]) return puts("IMPOSSIBLE"), 0;
	} puts("POSSIBLE");
	for (int i = 1; i <= n; ++i) {
		printf("%d ", bel[i] < bel[i + n]);
	}return 0;
}