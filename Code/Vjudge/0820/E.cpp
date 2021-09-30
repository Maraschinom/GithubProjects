#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e6 + 5;

int n, p, q, m, cnt, r;
int f[N], pre[N], a[N], d[N], k[N], w[N];

signed main() {
	n = read(), m = read(), r = read();
	for (int i = 1; i <= n; ++i)
		d[i] = read(), k[i] = read(), w[i] = read(), pre[i] = 1;
	for (int i = 1; i <= m; ++i) {
		p = read(), q = read();
		for (int j = 1; j <= q; ++j)
			a[++ cnt] = p;
	} sort(a + 1, a + 1 + cnt);
	for (int i = 1; i <= cnt; ++i) {
		f[i] = f[i - 1] + r;
		for (int j = 1; j <= n; ++j) {
			while(pre[j] + k[j] - 1 < i || a[pre[j]] + d[j] - 1 < a[i]) ++ pre[j];
			f[i] = min(f[i], f[pre[j] - 1] + w[j]);
		}
	} return printf("%d\n", f[cnt]), 0;
}