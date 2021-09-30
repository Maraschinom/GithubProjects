#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

#define int long long

namespace io {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
};

using io::read;

const int N = 1e4;
int T, n, k, p;
int fac[2005][N + 5], inv[2005][N + 5];

int prime[N + 5], idx[N + 5], prime_count;
bool mark[N + 5];

void get_prime() {
	for (int i = 2; i <= N; ++i) {
		if (!mark[i]) prime[++prime_count] = i, idx[i] = prime_count;
		for (int j = 1; j <= prime_count && i * prime[j] <= N; ++j) {
			mark[i * prime[j]] = true; if (!(i % prime[j])) break;
		}
	}
}

int qpow(int x, int y, int p) {
	int ans = 1; x %= p;
	for (; y; y >>= 1, x = (1LL * x * x) % p) if (y & 1) ans = (1LL * ans * x) % p;
	return ans % p;
}

int C(int n, int m, int p) {
	if (m > n) return 0;
	return 1LL * fac[idx[p]][n] * inv[idx[p]][n - m] % p * inv[idx[p]][m] % p;
}

int Lucas(int n, int m, int p) {
	if (n < p && m < p) return C(n, m, p);
	return (1LL * C(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
}

#define fre(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout);

signed main() {
	fre(b); T = read(); get_prime();
	for (int i = 1; i <= prime_count; ++i) {
		fac[i][0] = 1; for (int j = 1; j < prime[i]; ++j) fac[i][j] = fac[i][j - 1] * j % prime[i];
		inv[i][prime[i] - 1] = qpow(fac[i][prime[i] - 1], prime[i] - 2, prime[i]);
		for (int j = prime[i] - 2; ~j; --j) inv[i][j] = inv[i][j + 1] * (j + 1) % prime[i];
	}
	while (T--) {
		n = read(); k = read(); p = read(); k = min(n - k,k);
		printf("%lld\n", (Lucas(n + 1, k, p) + n - k) % p);
	}
}