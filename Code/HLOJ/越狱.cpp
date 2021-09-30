#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int mod = 100003;

int n, m;

int qpow(int x, int y) {
	int ans = 1;
	for (; y; y >>= 1, x = (1ll * x * x) % mod) if (y & 1) ans = (1ll * ans * x) % mod;
	return ans;
}

signed main() {
	m = read(), n = read();
	int all = qpow(m, n);
	int wrong = 1ll * m * qpow(m - 1, n - 1) % mod;
	printf("%d\n", (all - wrong + mod) % mod);
}