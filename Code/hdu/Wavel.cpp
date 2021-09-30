#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? ~x + 1 : x;
}

const int N = 5e5 + 5, mod = 998244353;
int T, n, m;
int a[N], b[N];
int sum[N][2], f[N][2];

signed main() {
	T = read();
	while (T--) {
		memset(sum, 0, sizeof sum);
		memset(f, 0, sizeof f);
		n = read(), m = read();
		for (int i = 1; i <= n; ++i) a[i] = read();
		for (int i = 1; i <= m; ++i) b[i] = read();
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int up = 1, down = 0;
			for (int j = 1; j <= m; ++j) {
				f[j][0] = f[j][1] = 0;
				if (a[i] == b[j])
					f[j][0] = up, f[j][1] = down,
					ans = (ans + up + down) % mod;
				else if (b[j] > a[i])
					up = (up + sum[j][1]) % mod;
				else
					down = (down + sum[j][0]) % mod; 
			}
			for (int j = 1; j <= m; ++j)
				sum[j][0] = (sum[j][0] + f[j][0]) % mod,
				sum[j][1] = (sum[j][1] + f[j][1]) % mod;
		} printf("%lld\n", ans);
	} 
	return 0;
} 
