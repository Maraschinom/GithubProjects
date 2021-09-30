#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 2e3 + 5, inf = 2147483647;

int n, ans, minn;
int a[N], b[N];
int f[N][N];

int solve() {
	for (int i = 1; i <= n; ++i) b[i] = a[i];
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; ++i) {
		minn = inf;
		for (int j = 1; j <= n; ++j) {
			minn = min(minn, f[i - 1][j]);
			f[i][j] = minn + abs(a[i] - b[j]);
		}
	}
	minn = inf;
	for (int i = 1; i <= n; ++i) minn = min(f[n][i], minn);
	return minn;
}

signed main() {
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	ans = solve(); reverse(a + 1, a + 1 + n);
	ans = min(ans, solve());
	return printf("%d\n", ans), 0;
}