#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

int read(int x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? ~x + 1 : x;
}

const int N = 5e4 + 5, mod = 201314;

int n, m, tot, root = 1, x, tim, l, r;
int Top[N], Son[N], Siz[N], anc[N], dfn[N];
vector<int> G[N];

struct Segment_tree {
	int l, r, sum, lazy;
}tree[N << 2];

class Issue{
public:
	int l, r, x, ans, id;
	Issue() {l = r = x = ans = id = 0;} 
	Issue(int _l, int _r, int _x, int _ans, int _id){
		l = _l, r = _r, x = _x, ans = _ans, id = _id;
	}
};

Issue Q[N << 1];

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define len(rt) (tree[rt].r - tree[rt].l + 1)

void build(int rt, int l, int r) {
	tree[rt].l = l, tree[rt].r = r;
	tree[rt].sum = 0, tree[rt].lazy = 0;
	if (l == r) return; int mid = l + r >> 1;
	build(lson, l, mid); build(rson, mid + 1, r);
}

void pushup(int rt) {
	tree[rt].sum = tree[lson].sum + tree[rson].sum; 
}

void pushdown(int rt) {
	if (tree[rt].lazy) {
		tree[lson].lazy += tree[rt].lazy;
		tree[rson].lazy += tree[rt].lazy;
		tree[lson].sum += len(lson) * tree[rt].lazy;
		tree[rson].sum += len(rson) * tree[rt].lazy;
		tree[rt].lazy = 0;
	}
}

void update(int rt, int l, int r, int val) {
	if (l <= tree[rt].l && tree[rt].r <= r) {
		tree[rt].sum += len(rt) * val;
		tree[rt].lazy += val;
		return;
	} pushdown(rt);
	int mid = tree[rt].l + tree[rt].r >> 1;
	if (l <= mid) update(lson, l, r, val);
	if (r > mid) update(rson, l, r, val);
	pushup(rt);
}

int query(int rt, int l,int r) {
	if (l <= tree[rt].l && tree[rt].r <= r) {
		return tree[rt].sum;
	} pushdown(rt); 
	int mid = tree[rt].l + tree[rt].r >> 1, ans = 0;
	if (l <= mid) ans += query(lson, l, r);
	if (r > mid) ans += query(rson, l, r);
	return ans;
}

void modify_chain(int x,int val) {
	while(x) {
		update(1, dfn[Top[x]], dfn[x], val);
		x = anc[Top[x]];
	}
}

int ask(int x) {
	int ans = 0;
	while (x) {
		(ans += query(1, dfn[Top[x]], dfn[x])) %= mod;
		x = anc[Top[x]];
	} return ans;
}

void dfs(int u, int pre) {
	Siz[u] = 1; anc[u] = pre;
	for (auto v : G[u]) if(v != pre) {
		dfs(v, u); Siz[u] += Siz[v];
		if (Siz[v] > Siz[Son[u]]) Son[u] = v;
	}
}

void dfs2(int u, int pre) {
	Top[u] = pre; dfn[u] = ++tim;
	if (Son[u]) dfs2(Son[u], pre);
	for (auto v : G[u])
		if (v != anc[u] && v != Son[u])
			dfs2(v, v);
}

bool compare(Issue a, Issue b) {
	return a.r < b.r;
}

bool comp(Issue a, Issue b) {
	return a.id < b.id;
}

signed main() {
	n = read(); m = read(); build(1, 1, n);
	for (int i = 1; i < n; ++i) {
		x = read() + 1; G[x].emplace_back(i + 1);
		G[i + 1].emplace_back(x);
	} dfs(root, 0); dfs2(root, root);
	for (int i = 1; i <= m; ++i) {
		l = read() + 1, r = read() + 1, x = read() + 1;
		Q[++ tot] = Issue{1, l - 1, x, 0, tot} ;
		Q[++ tot] = Issue{1, r, x, 0, tot} ;
	} sort(Q + 1, Q + 1 + tot, compare);
	int j = 1; while(j <= tot && !Q[j].r) ++ j;
	for (int i = 1; i <= n; ++i) {
		modify_chain(i, 1);
		while (Q[j].r == i)
			Q[j].ans = ask(Q[j].x), ++ j;
	}
	sort(Q + 1, Q + 1 + tot, comp);
	for (int i = 2; i <= tot; i += 2)
		printf("%d\n",(Q[i].ans - Q[i - 1].ans + mod) % mod);
	return 0;
}
