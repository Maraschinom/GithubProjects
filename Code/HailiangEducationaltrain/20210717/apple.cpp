#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <algorithm>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

#define fre(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout);
typedef long long LL;

const int N = 1e6 + 5, mod = 998244353;

int n, m;
LL g[30][N];
LL sum[N];
LL dp[N];

signed main(int argc, char *argv[]) {
	fre(apple); n = read(), m = read(); dp[0] = 1;
	for (int i = 1; i <= m; ++i) g[0][i] = 1;
	for (int i = 1; i <= 20; ++i) for (int j = 1; j <= m; ++j)
	for (int k = (j << 1); k <= m; k += j) (g[i][k] += g[i - 1][j]) %= mod;
	for (int i = 0; i <= 20; ++i) for (int j = 1; j <= m; ++j)
		(sum[i] += g[i][j] * ((i & 1) ? -1 : 1) + mod) %= mod;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= min(i, 20); ++j)
		(dp[i] += sum[j - 1] * dp[i - j]) %= mod;
	return printf("%lld\n",dp[n] % mod), 0;
}