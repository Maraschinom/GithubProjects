#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>

using namespace std;

int read(int x = 0, bool sign = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) sign |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return sign? ~x + 1 : x;
}

const int N = 1e5 + 5;

int n, m, x, y;

struct Segment_Tree {
	int l, r, sum;
	double mx;
}tree[N << 2];

#define lson (rt << 1)
#define rson (rt << 1 | 1)

int pushup(int rt,double mx) {
	if (tree[rt].mx <= mx) return 0;
	if (tree[rt].l == tree[rt].r) return tree[rt].mx > mx;
	if (tree[lson].mx <= mx) return pushup(rson, mx);
	else return pushup(lson, mx) + tree[rt].sum - tree[lson].sum;
}

void push_up(int rt) {
	tree[rt].sum = tree[lson].sum + pushup(rson, tree[lson].mx);
	tree[rt].mx = max(tree[lson].mx, tree[rson].mx);
}

void build(int rt, int l, int r) {
	tree[rt].l = l, tree[rt].r = r, tree[rt].mx = 0, tree[rt].sum = 0;
	if (l == r) return;
	int mid = l + r >> 1;
	build(lson, l, mid); build(rson, mid + 1, r);
}

void update(int rt, int l, int r, double mx) {
	if (tree[rt].l == tree[rt].r) {
		tree[rt].mx = mx, tree[rt].sum = 1;
		return;
	} int mid = tree[rt].l + tree[rt].r >> 1;
	if (l <= mid) update(lson, l, r, mx);
	else update(rson, l, r, mx);
	push_up(rt);
}

signed main() {
	n = read(), m = read(); build(1, 1, n);
	for (int i = 1; i <= m ; ++i) {
		x = read(), y = read();
		update(1, x, x, y * 1.0 / x);
		printf("%d\n",tree[1].sum);
	} return 0;
}
