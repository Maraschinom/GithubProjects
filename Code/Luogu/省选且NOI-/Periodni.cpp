/*
* @Author: Student01
* @Date:   2021-09-16 18:51:31
* @Last Modified by:   Student01
* @Last Modified time: 2021-09-16 19:52:09
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar())  f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 5e2 + 5, mod = 1e9 + 7, M = 1e6 + 5;

int n, m, top;
int fac[M], inv[M], siz[N], st[N], a[N];
int f[N][N], tr[N][2];

int qpow(int x, int y) {
	int ans = 1;
	for (; y; y >>= 1, x = (1ll * x * x) % mod) if (y & 1) ans = (1ll * ans * x) % mod;
	return ans;
}

int Combinatorial(int n, int m) {return n < m ? 0 : 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;}

void dfs(int x, int lst) {
	f[x][0] = siz[x] = 1;
	
	for (int i = 0; i < 2; ++i)
		if (tr[x][i]) {
			dfs(tr[x][i], a[x]); siz[x] += siz[tr[x][i]];
			for (int j = min(siz[x], m); ~j; --j)
				for (int k = 1; k <= min(siz[tr[x][i]], j); ++k)
					f[x][j] = (f[x][j] + 1ll * f[tr[x][i]][k] * f[x][j - k] % mod) % mod;
		}

	for (int i = min(siz[x], m); ~i; --i)
		for (int j = 1; j <= min(a[x] - lst, i); ++j)
			f[x][i] = (f[x][i] + 1ll * f[x][i - j] * fac[j] % mod * Combinatorial(a[x] - lst, j) % mod * Combinatorial(siz[x] - i + j, j) % mod) % mod;
}

signed main() {
	n = read(), m = read(); fac[1] = 1;
	for (int i = 2; i < M; ++i) fac[i] = (1ll * fac[i - 1] * i) % mod;
	inv[M - 1] = qpow(fac[M - 1], mod - 2);
	for (int i = M - 2; ~i; --i) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
	for (int i = 1, j; i <= n; ++i) {
		a[i] = read(); j = top;
		while (j && a[st[j]] > a[i]) --j;
		if (j) tr[st[j]][1] = i;
		if (j < top) tr[i][0] = st[j + 1];
		top = j; st[++ top] = i;
	}
	dfs(st[1], 0); return printf("%lld\n", f[st[1]][m]), 0;
}