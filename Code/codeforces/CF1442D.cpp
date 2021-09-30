#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e5 + 5;

int n, m, ans;
vector<int> a[N];
int c[N];
int f[20][N];

void merge(int l, int r, int dep) {
	if (l == r) {
		for (int i = m; i >= 0; --i) if (i + c[l] >= m)
			ans = max(ans, f[dep][i] + a[l][m - i]);
		return;
	} int mid = l + r >> 1;
	memcpy(f[dep + 1], f[dep], sizeof f[dep]);
	for (int i = mid + 1; i <= r; ++i) {
		if (c[i] <= m) for (int j = m - c[i]; ~j; --j)
		f[dep + 1][j + c[i]] = max(f[dep + 1][j + c[i]], f[dep + 1][j] + a[i][c[i]]);
	} merge(l, mid, dep + 1);

	memcpy(f[dep + 1], f[dep], sizeof f[dep]);
	for (int i = l; i <= mid; ++i) {
		if (c[i] <= m) for (int j = m - c[i]; ~j; --j)
		f[dep + 1][j + c[i]] = max(f[dep + 1][j + c[i]], f[dep + 1][j] + a[i][c[i]]);
	} merge(mid + 1, r, dep + 1);
}

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) {
		c[i] = read(), a[i].push_back(0);
		for (int j = 1; j <= c[i]; ++j)
			a[i].push_back(read()), a[i][j] += a[i][j - 1];
	} merge(1, n, 0);
	return printf("%lld\n", ans), 0;
}