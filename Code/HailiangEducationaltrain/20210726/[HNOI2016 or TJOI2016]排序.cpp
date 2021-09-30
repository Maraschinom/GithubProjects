#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cstring>

using namespace std;

int read(int x = 0, bool sign = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) sign |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return sign? ~x + 1 : x;
}

const int N = 2e5 + 5;

struct node {
    int l, r, sum, lazy;
}tree[N << 2];

#define lson (rt << 1)
#define rson (rt << 1 | 1)

int n, m, q, mid;
int opt[N], x[N], y[N], a[N];

void pushup(int rt) {
	tree[rt].sum = tree[lson].sum + tree[rson].sum;
}

void build(int rt, int l, int r) {
	tree[rt].l = l, tree[rt].r = r, tree[rt].lazy = -1;
	if (l == r) {
		tree[rt].sum = a[l] >= mid;
		return;
	} int mid = l + r >> 1;
	build(lson, l, mid); build(rson, mid + 1, r);
	pushup(rt);
}

void pushdown(int rt) {
	if (tree[rt].lazy >= 0) {
		tree[lson].lazy = tree[rt].lazy, tree[rson].lazy = tree[rt].lazy;
		tree[lson].sum = (tree[lson].r - tree[lson].l + 1) * tree[rt].lazy;
		tree[rson].sum = (tree[rson].r - tree[rson].l + 1) * tree[rt].lazy;
		tree[rt].lazy = -1;
	}
}

void update(int rt, int l, int r, int val) {
	if (l > tree[rt].r || r < tree[rt].l) return;
	if (l <= tree[rt].l && tree[rt].r <= r) {
		tree[rt].sum = (tree[rt].r - tree[rt].l + 1) * val;
		tree[rt].lazy = val;
		return;
	} pushdown(rt); int mid = tree[rt].l + tree[rt].r >> 1;
	update(lson, l, r, val);
	update(rson, l, r, val);
	pushup(rt);
}

int query(int rt, int l, int r){
	if (l > tree[rt].r || r < tree[rt].l) return 0;
	if (l <= tree[rt].l && tree[rt].r <= r) return tree[rt].sum;
	pushdown(rt); int mid = tree[rt].l + tree[rt].r >> 1;
	int ans = query(lson, l, r) + query(rson, l, r);
	pushup(rt); 
	return ans;
}

bool check() {
	build(1, 1, n);
	for (int i = 1; i <= m; ++i) {
		int res = query(1, x[i], y[i]);
		int l = x[i], r = y[i];
		if (!opt[i]) {
//			res = r - l + res - 1; 
			update(1, l, r - res, 0);
			update(1, r - res + 1, r, 1);
		} else {
			update(1, l, l + res - 1, 1);
			update(1, l + res, r, 0);
		}
	} return query(1, q, q);
}

signed main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1 ; i <= m; ++i)
		opt[i] = read(), x[i] = read(), y[i] = read(); 
    q = read(); int l = 1 , r = n , ans = -1; 
    while(l <= r) {
    	mid = l + r >> 1;
		if(check()) l = mid + 1 , ans = mid ;
		else r = mid - 1;
	} printf("%d\n",ans) ;
    return 0;
}

