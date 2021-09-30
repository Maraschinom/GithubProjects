#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e3 + 5;

int n;
int s[N], a[N];
int f[N][N];

signed main() {
	n = read(); memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; ++i) a[i] = read(), f[i][i] = 0;
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	for (int i = 1; i < n; ++i)
		for (int l = 1; l + i <= n; ++l) {
			int r = l + i;
			for (int k = l; k < r; ++k)
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
		} return printf("%d\n", f[1][n]), 0;
}