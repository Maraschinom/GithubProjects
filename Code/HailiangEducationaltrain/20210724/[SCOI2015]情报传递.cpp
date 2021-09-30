#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int read(int x = 0, bool sign = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) sign |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return sign? ~x + 1 : x;
}

typedef pair<int,int> PII;

const int N = 4e5 + 5;

int n, m, u, v, l, r, x, opt, tim, root;
int Top[N], Siz[N], Son[N], dep[N], dfn[N], anc[N];
vector<int> G[N];

struct Segment_Tree {
	int l, r, Tr;
};

struct Issue {
	int opt;
	int l, r, c;
	int x;
	int priority, idx;
	int ans1, ans2;
	friend bool operator < (const Issue &a, const Issue &b) {
		if (a.priority == b.priority) return a.opt < b.opt; 
		return a.priority < b.priority;
	}
};

Segment_Tree St[N << 1];
Issue Q[N];

void build(int rt, int l, int r) {
	St[rt].l = l, St[rt].r = r, St[rt].Tr = 0;
	if (l == r) return ;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void push_up(int rt) {
	St[rt].Tr = St[rt << 1].Tr + St[rt << 1 | 1].Tr;
}

void update(int rt, int l, int r) {
	if (l <= St[rt].l && St[rt].r <= r) {
		St[rt].Tr = 1;
		return;
	}
	int mid = St[rt].l + St[rt].r >> 1;
	if (l <= mid) update(rt << 1, l, r);
	if (r > mid) update(rt << 1 | 1, l, r);
	push_up(rt);
}

int query(int rt, int l, int r) {
	if (l <= St[rt].l && St[rt].r <= r)
		return St[rt].Tr;
	int mid = St[rt].l + St[rt].r >> 1, ans = 0;
	if (l <= mid) ans += query(rt << 1, l, r);
	if (mid < r) ans += query(rt << 1 | 1, l, r);
	return ans;
}

void dfs(int u,int pre) {
	dep[u] = dep[pre] + 1;
	Siz[u] = 1; anc[u] = pre;
	for (auto v : G[u]) {
		if (v == anc[u]) continue;
		dfs(v, u); Siz[u] += Siz[v];
		if (Siz[v] > Siz[Son[u]]) Son[u] = v;
	}
}

void dfs2(int u,int pre) {
	Top[u] = pre;
	dfn[u] = ++tim;
	if (!u) return;
	if (Son[u]) dfs2(Son[u],pre);
	for (auto v : G[u]) {
		if (v == Son[u]) continue;
		if (v == anc[u]) continue;
		dfs2(v,v);
	}
}

pair<int, int> lca(int x,int y) {
	int ans = 0, dx = dep[x], dy = dep[y];
	while(Top[x] != Top[y]) {
		if (dep[Top[x]] < dep[Top[y]])
			swap(x,y);
		ans += query(1, dfn[Top[x]], dfn[x]);
		x = anc[Top[x]];
	}
	if(dep[x] < dep[y]) x ^= y ^= x ^= y;
	ans += query(1, dfn[y], dfn[x]);
	return make_pair(dx + dy - 2 * dep[y] + 1, ans);
}

bool cmp (Issue a,Issue b) {
	return a.idx < b.idx;
}

signed main() {
	n = read();
	for (int i = 1; i <= n; ++i) {
		x = read();
		if(!x) root = i;
		else { 
			G[i].emplace_back(x);
			G[x].emplace_back(i);	
		} 
	} 
	dfs(root,0); dfs2(root,root);
	m = read(); build(1, 1, n);
	for (int i = 1; i <= m; ++i) {
		Q[i].opt = read(); Q[i].idx = i;
		if (Q[i].opt & 1) {
			Q[i].l = read(); Q[i].r = read();
			Q[i].c = read(); Q[i].priority = i - Q[i].c;
		} else {
			Q[i].x = read(); Q[i].idx = i;
			Q[i].priority = i;
		}
	}
	sort(Q + 1, Q + 1 + m);
	for (int i = 1; i <= m; ++i) {
		if (Q[i].opt & 1) {
			PII ans = lca(Q[i].l, Q[i].r);
			Q[i].ans1 = ans.first, Q[i].ans2 = ans.second;
		} else {
			update(1, dfn[Q[i].x], dfn[Q[i].x]);
		}
	}
	sort(Q + 1, Q + 1 + m, cmp);
	for (int i = 1; i <= m; ++i) {
		if (Q[i].opt & 1) printf("%d %d\n", Q[i].ans1, Q[i].ans2);
	}
}
