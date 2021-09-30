#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int read(int x = 0, bool sign = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) sign |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return sign? ~x + 1 : x;
}

const int N = 2e4 + 5;

int n, m, Q, ans, l, r, mid, idx;
int a[N], b[N], root[N], q[4];
vector<int> v[N];

struct Segment_Tree{
	int lson, rson;
	int sum, lmax, rmax;
}tree[N << 5];

void pushup(int rt) {
	tree[rt].sum = tree[tree[rt].lson].sum + tree[tree[rt].rson].sum;
	tree[rt].lmax = max(tree[tree[rt].lson].lmax, tree[tree[rt].lson].sum + tree[tree[rt].rson].lmax);
	tree[rt].rmax = max(tree[tree[rt].rson].rmax, tree[tree[rt].rson].sum + tree[tree[rt].lson].rmax);
}

void build(int& rt, int l, int r) {
	if (!rt) rt = ++ idx;
	if (l == r) {
		tree[rt].sum = tree[rt].lmax = tree[rt].rmax = 1;
		return;
	} int mid = l + r >> 1;
	build(tree[rt].lson, l, mid);
	build(tree[rt].rson, mid + 1, r);
	pushup(rt);
}

void update(int pre, int &rt, int l, int r, int id) {
	tree[rt = ++ idx] = tree[pre];
	if (l == r) {
		tree[rt].sum = tree[rt].lmax = tree[rt].rmax = -1;
		return;
	} int mid = l + r >> 1;
		if (id <= mid) update(tree[pre].lson, tree[rt].lson, l, mid, id);
		else update(tree[pre].rson, tree[rt].rson, mid + 1, r, id);
		pushup(rt);
}

int query(int rt, int l, int r, int L, int R) {
	if (R < L) return 0;
	if (l == L && r == R) return tree[rt].sum;
	int mid = l + r >> 1;
	if (R <= mid) return query(tree[rt].lson, l, mid, L, R);
	else if (L > mid) return query(tree[rt].rson, mid + 1, r, L, R);
	else return query(tree[rt].lson, l, mid, L, mid) + query(tree[rt].rson, mid + 1, r, mid + 1, R);
}

int queryl(int rt, int l, int r, int L, int R) {
	if (l == L && r == R) return tree[rt].lmax;
	int mid = l + r >> 1;
	if (R <= mid) return queryl(tree[rt].lson, l, mid, L, R);
	else if (L > mid) return queryl(tree[rt].rson, mid + 1, r, L, R);
	else {
		int ans1 = queryl(tree[rt].lson, l, mid, L, mid);
		int ans2 = query(tree[rt].lson, l, mid, L, mid) + queryl(tree[rt].rson, mid + 1, r, mid + 1, R);
		return max(ans1, ans2);
	}
}

int queryr(int rt, int l, int r, int L, int R) {
	if (l == L && r == R) return tree[rt].rmax;
	int mid = l + r >> 1;
	if (R <= mid) return queryr(tree[rt].lson, l, mid, L, R);
	else if (L > mid) return queryr(tree[rt].rson, mid + 1, r, L, R);
	else {
		int ans1 = queryr(tree[rt].rson, mid + 1, r, mid + 1, R);
		int ans2 = query(tree[rt].rson, mid + 1, r, mid + 1, R) + queryr(tree[rt].lson, l, mid, L, mid);
		return max(ans1, ans2);
	}
}

bool check(int x) {
	int all = query(root[x], 1, n, q[1] + 1, q[2] - 1);
	int ansleft = queryr(root[x], 1, n, q[0], q[1]);
	int ansright = queryl(root[x], 1, n, q[2], q[3]);
	return all + ansleft + ansright >= 0;
}

signed main() {
	n = read();
	build(root[0], 1, n);
	for (int i = 1; i <= n; ++i) a[i] = b[i] = read();
	sort(b + 1, b + 1 + n);
	m = unique(b + 1, b + 1 + n) - b - 1;
	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound(b + 1, b + 1 + m, a[i]) - b;
		v[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		root[i] = root[i - 1];
		for (auto u : v[i - 1])
			update(root[i], root[i], 1, n, u);
	} Q = read();
	for (int i = 1; i <= Q; ++i) {
		q[0] = read(), q[1] = read(), q[2] = read(), q[3] = read();
		for (int j = 0; j < 4; ++j) q[j] = (q[j] + ans) % n + 1;
		sort(q, q + 4); l = 1, r = m;
		while(l < r) {
			mid = l + r + 1 >> 1;
			if (check(mid)) l = mid;
			else r = mid - 1;
		} printf("%d\n",ans = b[l]);
	} return 0;
}
