#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}


const int N = 2e6 + 5, mod = 10007;

int n, ans, sum, u, v;
int w[N];
vector<int> G[N];

signed main() {
	n = read();
	for (int i = 1; i < n; ++i) {
		u = read(); v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) w[i] = read();
	for (int i = 1; i <= n; ++i) {
		int s = 0, s2 = 0, mx = 0, mx2 = 0;
		for (auto v : G[i]) {
			s = (w[v] + s) % mod;
			s2 = (w[v] * w[v] + s2) % mod;
			if (w[v] >= mx) mx2 = mx, mx = w[v];
			else mx2 = max(mx2, w[v]);
		}
		ans = max(mx2 * mx, ans); s = (s * s) % mod;
		sum = (sum + s - s2 + mod) % mod;
	} 
	return printf("%lld %lld\n", ans, sum % mod), 0;
}