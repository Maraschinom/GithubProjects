#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-') ;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? ~x + 1 : x;
}

const int N = 1e6 + 5;

int n, m, x, w, opt, rt, top;
int a[N], root[N];

struct Node {
	int l, r, sum;
}tree[N << 4];

int copy(int rt) {
	tree[++ top] = tree[rt];
	return top;
}

int build(int rt, int l, int r) {
	rt = ++top;
	if (l == r) {
		tree[rt].sum = a[l];
		return top;
	} int mid = l + r >> 1;
	tree[rt].l = build(tree[rt].l, l, mid); 
	tree[rt].r = build(tree[rt].r, mid + 1, r);
	return rt;
}

int update(int rt,int l,int r,int x,int val) {
	rt = copy(rt);
	if (l == r) {
		tree[rt].sum = val;
		return rt;
	} int mid = l + r >> 1;
	if (x <= mid) tree[rt].l = update(tree[rt].l, l, mid, x, val);
	else tree[rt].r = update(tree[rt].r, mid + 1, r, x, val);
	return rt;
}

int query(int rt,int l,int r,int x) {
	if (l == r) return tree[rt].sum;
	int mid = l + r >> 1;
	if (x <= mid) return query(tree[rt].l, l, mid, x);
	else return query(tree[rt].r, mid + 1, r, x);
}

signed main() {
	n = read(); m = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	root[0] = build(0, 1, n);
	for (int i = 1; i <= m; ++i) {
		rt = read(), opt = read(), x = read();
		if (opt & 1) {
			w = read();
			root[i] = update(root[rt], 1, n, x, w);
		} else {
			printf("%d\n",query(root[rt], 1, n, x));
			root[i] = root[rt];
		}
	} return 0;
}


