#include <iostream>
#include <cstdio>

using namespace std;

#define int long long

int read(int x = 0,char ch = getchar(),bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
	return f? ~x + 1 : x;
}

const int N = 1e5 + 5;

int n, m, opt, x, l, r, w, p;
int arr[N];

struct Segment_Tree {
	int l, r, tr, mx, lazy;
}Tree[N << 2];

#define lson (rt << 1)
#define rson (rt << 1 | 1)

void push_up(int rt) {
	Tree[rt].tr = Tree[lson].tr + Tree[rson].tr;
	Tree[rt].mx = max(Tree[lson].mx, Tree[rson].mx);
}


void build(int rt, int l, int r) {
	Tree[rt].lazy = 0, Tree[rt].tr = 0;
	Tree[rt].mx = 0, Tree[rt].l = l, Tree[rt].r = r;
	if (l == r) {
		Tree[rt].mx = Tree[rt].tr = read();
		return;
	} int mid = l + r >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	push_up(rt);
}

void update(int rt, int l, int r, int val) {
	if (Tree[rt].l == Tree[rt].r) {
		Tree[rt].tr = val;
		Tree[rt].mx = val;
		return;
	}
	int mid = Tree[rt].l + Tree[rt].r >> 1;
	if (l <= mid) update(lson, l, r, val);
	else update(rson, l, r, val);
	push_up(rt);
}

void mod(int rt, int l, int r, int p) {
	if (Tree[rt].mx < p) return;
	if (Tree[rt].l == Tree[rt].r) {
		Tree[rt].mx %= p;
		Tree[rt].tr = Tree[rt].mx;
		return; 
	} int mid = Tree[rt].l + Tree[rt].r >> 1;
	if (l <= mid) mod(lson, l, r, p);
	if (r > mid) mod(rson, l, r, p);
	push_up(rt);
}

int query(int rt, int l, int r) { 
	if (l <= Tree[rt].l && Tree[rt].r <= r) {
		return Tree[rt].tr;
	} int mid = Tree[rt].l + Tree[rt].r >> 1;
	int ans = 0;
	if (l <= mid) ans += query(lson, l, r);
	if (r > mid) ans += query(rson, l, r);
	return ans;
}

signed main() {
	n = read(), m = read();
	build(1, 1, n);
	for (int i = 1; i <= m; ++i) {
		opt = read();
		if (opt == 1)
			l = read(), r = read(), printf("%lld\n",query(1, l, r));
		if (opt == 2)
			l = read(), r = read(), p = read(), mod(1, l, r, p);
		if (opt == 3) 
			x = read(), w = read(), update(1, x, x, w);
	} return 0;
}
