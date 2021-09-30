#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long

int read(int x = 0, bool sign = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) sign |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return sign? ~x + 1 : x ;
}

const int N = 1e5 + 5;

int n, m, tim, u, v, w;
int Top[N], Son[N], Siz[N], dfn[N], anc[N], bel[N];
vector<int> G[N];

char opt[2];

struct Segment_Tree{
	int l, r, sum, lazy;
}Tree[N << 2];

struct Issue{
	int opt, u, v;
}Q[N];

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define len(rt) (Tree[rt].r - Tree[rt].l + 1)

void pushup(int rt) {
	Tree[rt].sum = Tree[lson].sum + Tree[rson].sum;
}

void pushdown(int rt) {
	if (Tree[rt].lazy)  {
		Tree[lson].lazy += Tree[rt].lazy;
		Tree[rson].lazy += Tree[rt].lazy;
		Tree[lson].sum += len(lson) * Tree[rt].lazy;
		Tree[rson].sum += len(rson) * Tree[rt].lazy;
		Tree[rt].lazy = 0;
	}
}

void build(int rt, int l, int r) {
	Tree[rt].l = l, Tree[rt].r = r;
	Tree[rt].sum = 1, Tree[rt].lazy = 0;
	if (l == r) return;
	int mid = l + r >> 1;
	build(lson, l, mid), build(rson, mid + 1, r);
}

void update(int rt, int l, int r, int val) {
	if (l <= Tree[rt].l && Tree[rt].r <= r) {
		Tree[rt].sum += len(rt) * val;
		Tree[rt].lazy += val; return;
	} pushdown(rt); int mid = Tree[rt].l + Tree[rt].r >> 1;
	if (l <= mid) update(lson, l, r, val);
	if (r > mid) update(rson, l, r, val);
	pushup(rt);
}

int query(int rt, int l, int r) {
	if (l <= Tree[rt].l && Tree[rt].r <= r) {
		return Tree[rt].sum;
	} pushdown(rt);
	int ans = 0, mid = Tree[rt].l + Tree[rt].r >> 1;
	if (l <= mid) ans += query(lson, l, r);
	if (r > mid) ans += query(rson, l, r);
	return ans;
}

int ask(int rt, int x) {
	if (Tree[rt].l == Tree[rt].r) return Tree[rt].sum;
	pushdown(rt); int mid = Tree[rt].l + Tree[rt].r >> 1;
	if (mid >= x) return ask(lson, x);
	else return ask(rson, x);
}

void dfs(int u, int pre) {
	anc[u] = pre; Siz[u] = 1;
	for (auto v : G[u]) if (v ^ pre){
		dfs(v, u); Siz[u] += Siz[v];
		if (Siz[v] > Siz[Son[u]]) Son[u] = v;
	}
}

void dfs2(int u, int pre) {
	Top[u] = pre, dfn[u] = ++tim;
	if (Son[u]) dfs2(Son[u], pre);
	for (auto v : G[u]) if (v ^ Son[u] && v ^ anc[u])
		dfs2(v,v);
}

int find(int x) {
	return bel[x] == x ? x : bel[x] = find(bel[x]);
}

void change(int x, int y,int val) {
	while (Top[x] ^ Top[y]) {
		update(1, dfn[Top[x]], dfn[x], val);
		x = anc[Top[x]];
	} update(1, dfn[y], dfn[x], val) ;
}

signed main(int argc, char *argv[]) {
	n = read(), m = read(); 
	for (int i = 1; i <= n; ++i) bel[i] = i;
	for (int i = 1; i <= m; ++i) {
		scanf("%s",opt + 1);
		Q[i].u = read(), Q[i].v = read();
		Q[i].opt = (opt[1] == 'Q');
		if (!Q[i].opt) {
			G[Q[i].u].push_back(Q[i].v);
			G[Q[i].v].push_back(Q[i].u);
		} bel[find(Q[i].u)] = find(Q[i].v);
	} for (int i = 1; i <= n; ++i) if (find(i) == i) G[n + 1].push_back(i);
	dfs(n + 1, 0); dfs2(n + 1, n + 1); build(1, 1, n + 1);
	for (int i = 1; i <= n; ++i) bel[i] = i;
	for (int i = 1; i <= m; ++i) {
		int u = Q[i].u, v = Q[i].v;
		if (anc[v] ^ u) swap(v, u);
		if (!Q[i].opt) {
			change(u, find(u), ask(1, dfn[v]));
			bel[find(v)] = find(u);
		} else {
			u = find(u); w = ask(1, dfn[v]);
			printf("%lld\n",w * (ask(1, dfn[u]) - w));
		}
	} return 0;
}
