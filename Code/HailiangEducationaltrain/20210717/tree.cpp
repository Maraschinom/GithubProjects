#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int read(int x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
typedef long long LL;

const int N = 1e5 + 5;
int n, m, u, v, tim, rt = 1;
int bfn[N];
int l[N][25], r[N][25];
bool vis[N];
int f[N][25];
vector<int> G[N];

class Segment_Tree {
private:
	__int128 Tr[N << 2], Lazy[N << 2];
public:
	Segment_Tree() { memset(Tr, 0, sizeof Tr); memset(Lazy, 0, sizeof Lazy); }

	void push_up(int rt) { Tr[rt] = Tr[rt << 1] + Tr[rt << 1 | 1]; }

	void push_down(int rt, int llen, int rlen) {
		if (Lazy[rt]) {
			Lazy[rt << 1] += Lazy[rt]; Lazy[rt << 1 | 1] += Lazy[rt];
			Tr[rt << 1] += Lazy[rt] * llen; Tr[rt << 1 | 1] += Lazy[rt] * rlen; Lazy[rt] = 0;
		} return;
	}

	void update(int rt, int l, int r, int L, int R, LL w) {
		if (L <= l && r <= R) {
			Tr[rt] += (r - l + 1) * w; Lazy[rt] += w; return;
		} int mid = l + r >> 1;
		push_down(rt, mid - l + 1, r - mid);
		if (L <= mid) update(rt << 1, l, mid, L, R, w);
		if (R > mid) update(rt << 1 | 1, mid + 1, r, L, R, w);
		push_up(rt);
	}

	__int128 query(int rt, int l, int r, int L, int R, __int128 ans = 0) {
		if (L <= l && r <= R) {
			return Tr[rt];
		} int mid = l + r >> 1;
		push_down(rt, mid - l + 1, r - mid);
		if (L <= mid) ans += query(rt << 1, l, mid, L, R);
		if (R > mid) ans += query(rt << 1 | 1, mid + 1, r, L, R);
		return ans;
	}
};

Segment_Tree Segment;

void dfs(int x, int pre) {
	f[x][0] = f[x][1] = pre;
	for (int i = 2; i < 25; ++i) f[x][i] = f[f[x][i - 1]][i - 2];
	for (auto v : G[x]) if (v != pre) dfs(v, x);
	return;
}

void bfs(int x) {
	queue<int> Q; Q.push(x);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		vis[u] = true; bfn[u] = ++tim;
		for (auto v : G[u]) if (!vis[v]) Q.push(v);
	}
}

void modify(int u, int val) {
	for (int i = 0; i < 25; ++i) {
		if (!r[u][i]) break;
		Segment.update(1, 1, n, l[u][i], r[u][i], val);
	} return;
}

__int128 query(int u) {
	__int128 ans = 0;
	for (int i = 0; i < 25; ++i) {
		if (!r[u][i]) break;
		ans += Segment.query(1, 1, n, l[u][i], r[u][i]);
	} return ans;
}

void write(__int128 x) {
	char P[25]; int cnt = 0;
	if (x < 0) putchar('-'), x = -x;
	if (x == 0) putchar('0');
	while (x) P[++cnt] = x % 10 + '0', x /= 10;
	for (int i = cnt; i; --i)putchar(P[i]);
	printf("\n");
}

signed main() {
	fre(tree); n = read();  m = read(); memset(l, 0x3f, sizeof l);
	for (int i = 1; i < n; ++i)
		u = read(), v = read(),
		G[u].push_back(v), G[v].push_back(u);
	dfs(1, 0); bfs(1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < 25; ++j)
			l[f[i][j]][j] = min(l[f[i][j]][j], bfn[i]),
			r[f[i][j]][j] = max(r[f[i][j]][j], bfn[i]);
	for (int i = 1; i <= n; ++i) l[i][0] = r[i][0] = bfn[i];
	for (int i = 1, opt; i <= m; ++i) {
		opt = read(); u = read();
		if (opt & 1) v = read(), modify(u, v);
		else write(query(u));
	} return 0;
}
