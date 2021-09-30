	/*
	* @Copyright: Copyright © 2021 昕橘玥
	* @Powered: Powered by .NET 5.0 on Kubernetes
	* @Author: JuyueXin.
	* @Date:   2021-09-17 18:20:28
	* @Email: 8950466@qq.com
	* @Last Modified by:   Maraschino
	* @Last Modified time: 2021-09-18 19:57:00
	*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int mod = 998244353, N = 3e5 + 5;

int n, m, ans, A, B;
int fac[N], inv[N];

int qpow(int x, int y) {
	int ans = 1;
	for (; y; y >>= 1, x = (1ll * x * x) % mod) if (y & 1) ans = (1ll * ans * x) % mod;
	return ans;
}

int C(int x, int y) {
	if (x < y) return 0;
	return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod;
}
signed main() {
	n = read(), A = read(), B = read(), m = read(); fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = (1ll * fac[i - 1] * i) % mod;
	inv[n] = qpow(fac[n], mod - 2);
	for (int i = n - 1; ~i; --i) inv[i] = (1ll * inv[i + 1] * (i + 1)) % mod;
	for (int i = 0; i <= n; ++i) {
		if (m < i * A) break;
		if (!((m - i * A) % B)) ans = (1ll * ans + 1ll * C(n, i) * C(n, (m - i * A) / B) % mod) % mod;
	} return printf("%lld\n", ans), 0;
}