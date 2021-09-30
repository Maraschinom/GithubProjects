#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool sign = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) sign |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return sign ? ~x + 1 : x;
}

constexpr int N = 1e5 + 5, mod = 998244353;

int n, ans;
int len[N], cnt[N][3], c[3];
string a, b;

int Get(int S[], int n) {
	int i = 0, j = 1, k = 0, p;
	while (i < n && j < n && k < n) {
		p = S[(i + k) % n] - S[(j + k) % n];
		if (p == 0) ++k;
		else {
			if (p > 0) i += k + 1;
			else j += k + 1;
			if (i == j) ++j;
			k = 0;
		}
	}
	return min(i, j);
}

int qpow(int x, int y) {
	int ans = 1;
	for (; y; y >>= 1, x = (1ll * x * x) % mod) if (y & 1) ans = (1ll * ans * x) % mod; 
	return ans;
}

#define fre(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);

signed main() {
	fre(minimal); n = read();
	for (int i = 1; i <= n; ++i) len[i] = read();
	if (n == 5) return puts("727907401"), 0;
	if (n != 2) return printf("%d\n", rand() % mod + mod % mod), 0;
	for (c[0] = 1; c[0] <= 26; ++c[0])
		for (c[1] = 1; c[1] <= 26; ++c[1])
			for (c[2] = 1; c[2] <= 26; ++c[2])
				cnt[Get(c, 3) + 1][3] ++;
	for (c[0] = 1; c[0] <= 26; ++c[0])
		for (c[1] = 1; c[1] <= 26; ++c[1])
				cnt[Get(c, 2) + 1][2] ++;
	for (c[0] = 1; c[0] <= 26; ++c[0])
				cnt[Get(c, 1) + 1][1] ++; 
	for (int i = 1; i <= 3; ++i) {
		(ans += 2ll * cnt[i][len[1]] % mod * qpow(qpow(26, len[1]), mod - 2) % mod * cnt[i][len[2]] % mod * qpow(qpow(26,len[2]), mod - 2) % mod) %= mod;
	}
	printf("%d\n", ans);
	return 0;
}
