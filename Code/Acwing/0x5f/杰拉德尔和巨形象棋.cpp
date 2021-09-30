/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-13 20:11:21
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-14 18:48:16
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 2e3 + 5, M = 2e5 + 5, mod = 1e9 + 7;

int inv[M], fac[M];
pair<int, int> a[N];
int f[N];

int h, w, n;

int C(int x, int y) {return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod;}

int qpow(int x, int y) {
	int ans = 1;
	for (; y; y >>= 1, x = (1ll * x * x) % mod) if (y & 1) ans = (1ll * ans * x) % mod;
	return ans;
}

signed main() {
	h = read(), w = read(), n = read();
    fac[0] = 1, inv[0] = 1;

    for (int i = 1; i < M; ++i) fac[i] = fac[i - 1] * i % mod;
    inv[M - 1] = qpow(fac[M - 1], mod - 2);
    for (int i = M - 2; i; --i) inv[i] = inv[i + 1] * (i + 1) % mod;

    for (int i = 1; i <= n; ++i) a[i].first = read(), a[i].second = read();
    a[++ n].first = h, a[n].second = w;
    
    sort(a + 1, a + 1 + n);
    
    for (int i = 1; i <= n; ++i) {
        int x = a[i].first, y = a[i].second;
        f[i] = C(x - 1 + y - 1, x - 1);
        for (int j = 1; j < i; ++j) if (a[j].first <= x && a[j].second <= y) 
            f[i] = (f[i] - f[j] * C(x - a[j].first + y - a[j].second, x - a[j].first) % mod) % mod;
    }
    return printf("%lld\n", (f[n] + mod) % mod), 0;
}