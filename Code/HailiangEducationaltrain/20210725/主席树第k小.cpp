#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int read(int x = 0, bool sign = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) sign |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
	return sign? ~x + 1 : x;
}

const int N = 2e5 + 5;

int n, m, len, l, r, k, idx;
int a[N], b[N],	root[N];

struct Segment_Tree{
	int sum, l, r;
}Tr[N << 5];

int build(int l, int r) {
	int rt = ++ idx;
	Tr[rt].sum = 0;
	int mid = l + r >> 1;
	if (l < r) 
		Tr[rt].l = build(l, mid), Tr[rt].r = build(mid + 1, r);
	return rt;
}

int update(int rt, int l, int r,int v) {
	int pre = ++ idx;
	Tr[pre].l = Tr[rt].l, Tr[pre].r = Tr[rt].r, Tr[pre].sum = Tr[rt].sum + 1;
	if (l < r) {
		int mid = l + r >> 1;
		if (v <= mid) Tr[pre].l = update(Tr[rt].l, l, mid, v);
		else Tr[pre].r = update(Tr[rt].r, mid + 1, r, v);
	} return pre;
}

int ask(int L, int R, int l, int r, int k) {
	if (l >= r) return l;
	int x = Tr[Tr[R].l].sum - Tr[Tr[L].l].sum;
	int mid = l + r >> 1;
	if (x >= k) return ask(Tr[L].l, Tr[R].l, l, mid, k);
	else return ask(Tr[L].r, Tr[R].r, mid + 1, r, k - x);
}

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i)
		b[i] = a[i] = read();
	sort(b + 1, b + 1 + n);
	len = unique(b + 1, b + 1 + n) - b - 1;
	root[0] = build(1, len);
	for (int i = 1; i <= n; ++i)
		root[i] = update(root[i - 1], 1, len, lower_bound(b + 1, b + 1 + len, a[i]) - b);
	while (m --) {
		l = read(), r = read(), k = read();
		int ans = ask(root[l - 1], root[r], 1, len, k);
		printf("%d\n", b[ans]);
	} return 0;
}
