/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-13 18:29:38
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-13 18:44:20
*/

#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 2e3 + 5, mod = 1e9 + 7;

int n, m, ans;
int a[N];
int c[N][N];

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= m; ++i) a[i] = read();
	c[0][0] = 1;
	for (int i = 1; i <= 2000; ++i) {
		c[i][i] = c[i][0] = 1;
		for (int j = 1; j <= i; ++j) (c[i][j] = c[i - 1][j - 1] + c[i - 1][j]) %= mod;
	}
	for (int i = 0; i < n; ++i) {
		int res = 1;
		for (int j = 1; j <= m; ++j)
			res = (1ll * res * c[n + a[j] - i - 1][n - i - 1]) % mod;
		ans = (ans + 1ll * res * ((i & 1) ? -1 : 1) * c[n][i] % mod + mod) % mod;
	} return printf("%d\n", ans), 0;
}