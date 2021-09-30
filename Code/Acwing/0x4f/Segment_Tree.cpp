#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x; 
}

#define int long long

const int N = 1e5 + 5;

int n, m, l, r, d;
char ch[2];
int a[N];

namespace ST{
	struct Segment{	
		int val, l, r, lazy, len;
		Segment(){val = l = r = lazy = 0;}
	}tr[N << 2];
	
	void pushup(int rt) {
		tr[rt].val = tr[rt << 1].val + tr[rt << 1 | 1].val; 
	}
	
	void pushdown(int rt) {
		if (tr[rt].lazy) {
			tr[rt << 1].lazy += tr[rt].lazy;
			tr[rt << 1 | 1].lazy += tr[rt].lazy;
			tr[rt << 1].val += tr[rt].lazy * tr[rt << 1].len;
			tr[rt << 1 | 1].val += tr[rt].lazy * tr[rt << 1 | 1].len;
			tr[rt].lazy = 0;
		}
	}

	void build(int rt, int l, int r) {
		tr[rt].l = l, tr[rt].r = r; tr[rt].len = r - l + 1;
		if (l == r) return tr[rt].val = a[l], void();
		int mid = l + r >> 1;
		build(rt << 1, l, mid);
		build(rt << 1 | 1, mid + 1, r);
		pushup(rt); 
	}
	
	void modify(int rt, int l, int r, int w) {
		if (l <= tr[rt].l && tr[rt].r <= r) {
			tr[rt].lazy += w, tr[rt].val += tr[rt].len * w;
			return ; 
		} pushdown(rt);
		int mid = tr[rt].l + tr[rt].r >> 1;
		if (l <= mid) modify(rt << 1, l, r, w);
		if (r > mid) modify(rt << 1 | 1, l, r, w);
		pushup(rt);
	}
	
	int query(int rt, int l, int r) {
		if (l <= tr[rt].l && tr[rt].r <= r)
			return tr[rt].val;
		pushdown(rt);
		int mid = tr[rt].l + tr[rt].r >> 1, ans = 0;
		if (l <= mid) ans += query(rt << 1, l, r);
		if (r > mid) ans += query(rt << 1 | 1, l, r);
		return ans;
	}
}; 

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	ST::build(1, 1, n);
	for (int i = 1; i <= m; ++i) {
		scanf("%s",ch); l = read(), r = read();
		if (ch[0] == 'C') {
			d = read();
			ST::modify(1, l, r, d);
		} else {
			printf("%lld\n", ST::query(1, l, r));
		}
	}
}
