#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar())	x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 5e5 + 5;

int n, m, x, y, val;
int a[N], b[N], s[N];
char opt[2];

#define lowbit(x) ((x)&(-(x)))

int gcd(int x, int y) {return !y ? x : gcd(y, x % y);}

namespace Segment_Tree{
	struct Segment_Tree {
		int l, r, Gcd;
	}tr[N << 2];

	#define ls (rt << 1)
	#define rs (rt << 1 | 1)

	void pushup(int rt) {
		tr[rt].Gcd = gcd(tr[ls].Gcd, tr[rs].Gcd);
	}

	void build(int rt, int l, int r) {
		tr[rt].l = l, tr[rt].r = r;
		if (l == r) return tr[rt].Gcd = b[l], void();
		int mid = l + r >> 1; build(ls, l, mid);
		build(rs, mid + 1, r); pushup(rt);
	}

	void update(int rt, int x, int w) {
		if (tr[rt].l == tr[rt].r) {
			tr[rt].Gcd += w; return;
		} int mid = tr[rt].l + tr[rt].r >> 1;
		if (x <= mid) update(ls, x, w);
		else update(rs, x, w);
		pushup(rt);
	}

	int query(int rt, int l, int r) {
		if (l <= tr[rt].l && tr[rt].r <= r) {
			return tr[rt].Gcd;
		} int mid = tr[rt].l + tr[rt].r >> 1, ans = 0;
		pushup(rt);
		if (l <= mid) ans = gcd(ans, query(ls, l, r));
		if (r > mid) ans = gcd(ans, query(rs, l, r));
		return abs(ans);
	}
};

void add(int x, int v) {
	for (; x <= n; x += lowbit(x)) s[x] += v;
}

int ask(int x) {
	int ans = 0;
	for (; x; x -= lowbit(x)) ans += s[x];
	return ans;
}

using namespace Segment_Tree;

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read(), b[i] = a[i] - a[i - 1];
	build(1, 1, n);
	for (int i = 1; i <= m; ++i) {
		scanf("%s", opt); x = read(), y = read();
		if (opt[0] == 'Q') {
			int tmp = a[x] + ask(x);
			printf("%lld\n", gcd(tmp, query(1, x + 1, y)));
		} else {
			val = read(); add(x, val); add(y + 1, -val);
			update(1, x, val); 
			if (y < n) update(1, y + 1, -val);
		}
	} return 0;
}