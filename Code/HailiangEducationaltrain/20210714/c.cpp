/*
* * * * * * * * * *
 @Author : Mukrus
 @Date : 2021-7-14
* * * * * * * * * *

ȴ��С�ĵִ��˼���ı˰�

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define int long long 

int read(int x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define add(x,y) ((((x) % mod) + ((y) % mod)) % mod)
#define reduce(x,y) ((((x) % mod) - ((y) % mod) + mod) % mod)
#define mul(x,y) (int)((1LL * ((x) % mod) * ((y) % mod)) % mod)

const int N = 2e3 + 5, mod = 998244353;
int n;
int a[N], fac[N], inv[N], cnt[N];
int g[N][N], f[N][N];

int qpow(int x, int y) {
	int ans = 1;
	for (; y; y >>= 1, x = mul(x, x)) if (y & 1) ans = mul(ans, x);
	return ans;
}

int C(int n, int m) {
	if (n < m) return 0 ;
	return mul(mul(fac[n], inv[m]), inv[n - m]);
}

signed main(int argc, char* argv[]) {
	fre(c);
	n = read(), fac[0] = 1;
	for (int i = 1; i <= n; ++i)
		a[i] = read(),
		cnt[a[i]] ++,
		fac[i] = mul(fac[i - 1],i);
	inv[n] = qpow(fac[n], mod - 2);
	for (int i = n - 1; ~i; --i)
		inv[i] = mul(inv[i + 1], i + 1);
	for (int j = 1; j <= n; ++j) {
		g[0][j] = 1;
		for (int i = j; i <= n; i += j)
			g[i][j] = mul(g[i - j][j], C(i - 1, j - 1));
	}
	f[n + 1][0] = 1;
	for (int i = n + 1; i > 1; --i)
		for (int j = 0; j <= n; ++j)
			for (int k = 0; k * (i - 1) <= j + cnt[i - 1]; ++k)
				f[i - 1][j + cnt[i - 1] - k * (i - 1)] = add(f[i - 1][j + cnt[i - 1] - k * (i - 1)], mul(f[i][j], mul(C(j + cnt[i - 1], k * (i - 1)), g[k * (i - 1)][i - 1])));
	return printf("%d\n", f[1][0]), 0;
}
/*
Input:
3
2 3 3
Output:
4
*/
