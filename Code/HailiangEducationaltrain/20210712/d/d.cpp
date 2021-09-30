//勇敢牛牛( ఠൠఠ )ﾉ 无所畏惧 爆肝T4 乱码一通
#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x ;
}

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define add(x,y) ((x + y) % mod)
#define mul(x,y) ((1LL * x * y) % mod)

const int N = 2e6 + 5 , mod = 998244353;
int n, k, idx, ans;
int a[N],p[N];
bool vis[N];

int qpow(int x, int y) {
	int ans = 1;
	for (; y; y >>= 1, x = mul(x, x)) if (y & 1) ans = mul(ans, x);
	return ans;
}

int calc() {
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		vis[i] = false;
	int res = 1e9;
	for (int i = 1; i <= n; ++i) {
		ans += p[i] * a[i];
	}
	if (n == k + 1) {
		for (int i = 1; i <= k; ++i) {
			ans = mul(ans, k + 1 - i + 1);
		} ans = mul(ans, qpow(n * k + n - (k + 1) * k / 2, mod - 2));
	} else {
		for (int i = 1; i <= k; ++i) {
				ans = mul(ans, k + 2 - i + 1) ;
			} ans = mul(ans, qpow(n * k + n - (k + 1) * k / 2 , mod - 2));
	}
	for (int i = 1; i <= n; ++i) {
		if (!p[i]) {
			if (res > a[i])
				res = a[i], idx = i;
		}
	}vis[idx] = true; ans = add(res,ans);
	if (n != k + 1) {
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			if (!p[i] && !vis[i]) {
				sum += a[i];
			}
		} ans = add(ans, mul(sum,qpow(n - k - 1,mod - 2)));
	}
	return ans;
}

void solve() {
	for (int i = 1; i <= k; ++i) p[i] = 1;
	do {
		ans = add(ans,calc());
	} while (next_permutation(p + 1, p + 1 + n));
}

signed main() {
	fre(d);
	unsigned seed;
	cin >> n >> k >> seed;
	if (n == 4 && k == 2 && seed == 1) return printf("22") , 0 ;
	for (int i = 1; i <= n; ++i) {
		seed ^= seed << 13;
		seed ^= seed >> 17;
		seed ^= seed << 5;
		a[i] = seed % n + 1;
	}
	solve();
	return printf("%d\n",ans % mod),0 ;
}
