/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-14 19:21:02
* @Email: 8950466@qq.com
* @Last Modified by:   Maraschino
* @Last Modified time: 2021-09-18 19:54:36
*/

#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

template

const int N = 5e4 + 5;

int n, tim, m, x, y, d;
int a[N], son[N], siz[N], Top[N], dep[N], anc[N], dfn[N];
vector<int> G[N];


namespace newSTL {
	int abs(int x) {return x > 0 ? x : -x;}
	int gcd(int x, int y) {return !y ? x : gcd(y, x % y);}
};

namespace prepare {

	void dfs(int x) {

		siz[x] = 1, dep[x] = dep[anc[x]] + 1;

		for (auto v : G[x]) {
			if (v == anc[x]) continue;
			anc[v] = x; dfs(v); siz[x] += siz[v];
			if (!son[x] || siz[v] > siz[son[x]]) son[x] = v;
		} return;
	}

	void dfs(int x, int top) {
		Top[x] = top; dfn[x] = ++ tim;

		if (son[x]) dfs(son[x], top);

		for (auto v : G[x]) {
			if (v == anc[x] || v == son[x]) continue;
			dfs(v, v);
		} return;
	}
};

namespace Segment_Tree { // Use Segment_Tree to defent Differential Array.

	struct Segment_Tree{
		int val, l, r;
	}tr[N << 2];

	#define ls (rt << 1)
	#define rs (rt << 1 | 1)

	void pushup(int rt) {tr[rt].val = newSTL::gcd(tr[ls].val, tr[rs].val);} // Merge the gcd on two section.

	void build(int rt, int l, int r) {
		tr[rt].l = l, tr[rt].r = r;

		if (l == r) {
			tr[rt].val = a[l];
			return;
		}

		int mid = l + r >> 1;

		build(ls, l, mid), build(rs, mid + 1, r); pushup(rt);
	}

	void update(int rt, int x, int d) {
		if (tr[rt].l == tr[rt].r) {
			tr[rt].val += d;
			return;
		}

		int mid = tr[rt].l + tr[rt].r >> 1;

		if (x <= mid) update(ls, x, d);
		else update(rs, x, d);
		pushup(rt);
	}

	int query(int rt, int l, int r) {
		if (l <= tr[rt].l && tr[rt].r <= r)
			return tr[rt].val;

		int mid = tr[rt].l + tr[rt].r >> 1, ans = 0;

		if (l <= mid) ans = newSTL::gcd(ans, query(ls, l, r));
		if (r > mid) ans = newSTL::gcd(ans, query(rs, l, r));
		return newSTL::abs(ans);
	}
};

namespace Tree_Array { // Use Tree_Array(BIT) to find the truly value of the array called a.

	int s[N];

	#define lowbit(x) (x)&(-x) // find the last 1 in the Binary representation.

	void update(int x, int d) {if (!x) return; for (; x <= n; x += lowbit(x)) s[x] += d;} // add d at the position x



	int query(int x, int ans = 0) {for (; x; x -= lowbit(x)) ans += s[x]; return ans;} // query the sum from 1 to x on the Tree_Array.
} // We can use only O(nlogn) times to solve n problems by Tree_Array.

namespace operate{

	void update_chain(int x, int y, int d) { // This function is to change a chain to add d to the chain.
		while (Top[x] != Top[y]) {
			if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
			Segment_Tree::update(1, dfn[Top[x]], -d); // Change the Differentail Array, reduce d at the top of the chain.
			if(son[x]) Segment_Tree::update(1, dfn[son[x]], d); // And add d between 1 and the heavy son's index. It means that you add d between dfn[son[x]] to dfn[Top[x]].
			Tree_Array::update(dfn[Top[x]], d);
			Tree_Array::update(dfn[x] + 1, -d); // Add d between dfn[x] + 1 and dfn[Top[x]]. We reduce time in the form of difference.
			x = anc[Top[x]]; // X jumps to the father of the chain's top.
		} if (dfn[x] < dfn[y]) swap(x, y);
		Segment_Tree::update(1, dfn[y], -d);
		if (son[x]) Segment_Tree::update(1, dfn[son[x]], d);
		Tree_Array::update(dfn[y], d);
		Tree_Array::update(dfn[x] + 1, -d);
		// Like any other "Heavy Light Decomposition of a tree", this step is necessary.
	}

	int query_chain(int x, int y) {
		int ans = 0;
		while (Top[x] != Top[y]) {
			if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
			int res = newSTL::gcd(Segment_Tree::query(1, dfn[Top[x]] + 1, dfn[x]), Tree_Array::query(dfn[Top[x]]));
			ans = newSTL::gcd(res, ans);
			x = anc[Top[x]];
		} if (dfn[x] < dfn[y]) swap(x, y);
		int res = newSTL::gcd(Segment_Tree::query(1, dfn[y] + 1, dfn[x]), Tree_Array::query(dfn[y]));
		return newSTL::abs(newSTL::gcd(ans, res));
	}
};

signed main() {
	n = read();
	for (int i = 1; i < n; ++i) {
		x = read() + 1, y = read() + 1;
		G[x].push_back(y), G[y].push_back(x);
	} prepare::dfs(1), prepare::dfs(1, 1);
	for (int i = 1; i <= n; ++i) a[dfn[i]] = read();
	for (int i = 1; i <= n; ++i) Tree_Array::update(dfn[i], a[dfn[i]]), Tree_Array::update(dfn[i] + 1, -a[dfn[i]]);
	// Use the value add on the position.
	for (int i = n; i; --i) a[i] = a[i - 1] - a[i];
	Segment_Tree::build(1, 1, n); m = read();
	for (int i = 1; i <= m; ++i) {
		char opt[2]; scanf("%s", opt);
		x = read() + 1, y = read() + 1; // Index is from 0 to start.
		if (opt[0] == 'F') printf("%d\n", operate::query_chain(x, y));
		else {
			d = read();
			operate::update_chain(x, y, d);
		}
	} return 0;
}