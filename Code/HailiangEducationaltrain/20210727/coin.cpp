#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool sign = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) sign |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return sign? ~x + 1 : x;
}

const int N = 1e5 + 5;

int n, k, ans;
int a[N];
bool vis[N];

int check(int x) {
	int ans = 0;
	for (int i = n - k; i; --i) {
		if (x >> i & 1) {
			if (vis[i]) return 0;
			vis[i] = true; vis[i + k] = true;
			ans += a[i] + a[i + k];
		}
	} return ans;
}

#define fre(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);

signed main() {
	fre(coin); n = read(), k = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 0; i <= (1 << n - k); ++i) {
		ans = max(ans, check(i));
		for (int j = 0; j <= n - k; ++j) vis[j] = false;
	} return printf("%d\n", ans);
}
