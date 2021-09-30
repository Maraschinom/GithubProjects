#include <iostream>
#include <cstdio>

using namespace std;

const int N = 5e5 + 5, mod = 1 << 20;

int n, m, opt, l, r, x, ans, lst, mx, mn;
int a[N];

signed main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i) scanf("%d",&a[i]);
	for (int i = 1; i <= m; ++i) {
		scanf("%d",&opt);
		scanf("%d%d",&l,&r);
		l ^= lst, r ^= lst;
		if (opt & 1) {
			scanf("%d",&x); x ^= lst;
			for (int i = l; i <= r; ++i)
				a[i] -= (a[i] > x) * x;
		} else {
			ans = 0; mx = 0, mn = 2147483647;
			for (int i = l; i <= r; ++i)
				ans += a[i], mx = max(mx,a[i]), mn = min(mn,a[i]);
			printf("%d %d %d\n", ans, mn, mx);
			lst = ans % mod;
		}
	} return 0;
}
