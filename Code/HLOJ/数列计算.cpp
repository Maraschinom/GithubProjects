#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 5e4 + 5, mod = 1e9 + 7;

int T, n, ans, type;
int a[N];

signed main() {
	freopen("seqcalc.in", "r", stdin);
	freopen("seqcalc.out", "w", stdout);
	T = read();
	while (T--) {
		n = read(); type = read(); ans = 0;
		for (int i = 1; i <= n; ++i) a[i] = read();
		if (type & 1) {
			sort(a + 1, a + 1 + n);
			for (int i = 1; i < n; ++i)
				(ans += (1LL * (a[i + 1] - a[i]) * (n - i) * i) % mod) %= mod;
		} else {
			int res = 0;
			for (int i = 1; i <= n; ++i)
				res += a[i] * a[i] % mod, res %= mod;
			res %= mod, res *= n; res %= mod;
				ans += a[i], ans %= mod;
			ans *= ans; ans %= mod;
			ans = (res - ans + mod) % mod;
		} printf("%lld\n", (ans % mod + mod) % mod);
	}
}