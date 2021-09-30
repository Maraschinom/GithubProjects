#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 2e5 + 5;

int n, ans;
int a[N];

namespace Segment_Tree{

	struct Segment_Tree{
		int l, r;
		std::vector<int> v;
	}tr[N << 2];

	#define ls (rt << 1)
	#define rs (rt << 1 | 1)

	void pushup(int rt) {
		tr[rt].v = tr[ls].v;
		for (int i = 0; i < tr[rs].r - tr[rs].l + 1; ++i)
			tr[rt].v.emplace_back(tr[rs].v[i]);
		sort(tr[rt].v.begin(), tr[rt].v.end());
	}

	void build(int rt, int l, int r) {
		tr[rt].l = l, tr[rt].r = r;
		if (l == r) {
			tr[rt].v.push_back(a[l]);
			return;
		} int mid = l + r >> 1;
		build(ls, l, mid); build(rs, mid + 1, r);
		pushup(rt);
	}

	int ask(int rt, int l, int r, int v) {
		if (l <= tr[rt].l && tr[rt].r <= r)
			return lower_bound(tr[rt].v.begin(), tr[rt].v.end(), v) - tr[rt].v.begin();
		int mid = tr[rt].l + tr[rt].r >> 1, ans = 0;
		if (l <= mid) ans += ask(ls, l, r, v);
		if (r > mid) ans += ask(rs, l, r, v);
		return ans;
	}

};

using namespace Segment_Tree;

signed main() {
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = min(read(), n);
	build(1, 1, n);
	if (n == 1) return puts("0"), 0;
	ans = (n - 1) * n >> 1LL;
	for (int i = 1; i <= n; ++i) {
		ans -= n - a[i];
		if (a[i] + 1 <= i) ++ ans;
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] == n) continue;
		ans += ask(1, max(a[i], i) + 1, n, i);
	} return printf("%lld\n", ans), 0;
}