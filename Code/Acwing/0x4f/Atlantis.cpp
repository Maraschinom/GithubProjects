#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e4 + 5;

int n, tot, CNT; 
double x[2], y[2];
double val[N << 1];
double area;

namespace Segment_Tree{

	double sum[N << 2];
	int cnt[N << 2];

	#define ls (rt << 1)
	#define rs (rt << 1 | 1)

	void pushup(int rt, int l, int r) {
		if (cnt[rt]) sum[rt] = val[r + 1] - val[l];
		else sum[rt] = sum[ls] + sum[rs];
	}

	void update(int rt, int l, int r, int L, int R, int w) {
		if (l <= L && R <= r) {
			cnt[rt] += w; pushup(rt, L, R); return;
		} int mid = L + R >> 1;
		if (l <= mid) update(ls, l, r, L, mid, w);
		if (r > mid) update(rs, l, r, mid + 1, R, w); pushup(rt, L, R);
	}

};

struct Line{
	double l, r, h; int d;
	friend bool operator < (const Line a, const Line b) {
		return a.h < b.h;
	}
}l[N];

using namespace Segment_Tree;

signed main() {
	for (int Case = 1; Case; ++ Case) {
		n = read(); if (!n) return 0;
		memset(cnt, 0, sizeof cnt), memset(sum, 0, sizeof sum);
		area = 0, CNT = tot = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%lf%lf%lf%lf", &x[0], &y[0], &x[1], &y[1]);
			val[++ CNT] = x[0], val[++ CNT] = x[1];
			l[++ tot] = {x[0], x[1], y[0], 1};
			l[++ tot] = {x[0], x[1], y[1], -1};
		} sort(val + 1, val + 1 + CNT); sort(l + 1, l + 1 + tot);
		n = unique(val + 1, val + 1 + CNT) - val - 1;
		for (int i = 1; i < tot; ++i) {
			int L = lower_bound(val + 1, val + 1 + n, l[i].l) - val;
			int R = lower_bound(val + 1, val + 1 + n, l[i].r) - val - 1;
			update(1, L, R, 1, n - 1, l[i].d);
			area += sum[1] * (l[i + 1].h - l[i].h);
		}  printf("Test case #%d\nTotal explored area: %.2lf\n\n", Case, area);
	}
}