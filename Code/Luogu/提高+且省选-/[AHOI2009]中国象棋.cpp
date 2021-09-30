/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-13 18:57:55
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-13 19:18:19
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e2 + 5, mod = 9999973;

int n, m, ans;
int fac[N];
int f[N][N][N];

int qpow(int x, int y) {
	int ans = 1;
	for (; y; y >>= 1, x = (1ll * x * x) % mod) if (y & 1) ans = (1ll * ans * x) % mod;
	return ans;
}

int w(int x) {return x * (x - 1) % mod * qpow(2, mod - 2) % mod;}

signed main() {
	n = read(), m = read();
	f[0][0][0] = 1, fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = (1ll * fac[i - 1] * i) % mod;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			for (int k = 0; k <= m - j; ++k) {
				f[i][j][k] += f[i - 1][j][k];
				if (j) f[i][j][k] = (f[i][j][k] + 1ll * f[i - 1][j - 1][k] * (m - j - k + 1) % mod) % mod;
				if (k) f[i][j][k] = (f[i][j][k] + 1ll * f[i - 1][j + 1][k - 1] * (j + 1) % mod) % mod,
					   f[i][j][k] = (f[i][j][k] + 1ll * f[i - 1][j][k - 1] * j * (m - j - k + 1) % mod) % mod;
				if (j > 1) f[i][j][k] = (f[i][j][k] + 1ll * f[i - 1][j - 2][k] * w(m - j - k + 2) % mod) % mod;
				if (k > 1) f[i][j][k] = (f[i][j][k] + 1ll * f[i - 1][j + 2][k - 2] * (j + 2) % mod * (j + 1) % mod * qpow(2, mod - 2) % mod) % mod;
			}
	for (int i = 0; i <= m; ++i) for (int j = 0; j <= m; ++j) ans = (ans + f[n][i][j]) % mod;
	return printf("%lld\n", ans), 0;
}