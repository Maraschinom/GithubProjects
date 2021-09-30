#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e5 + 5, M = 1e9;

unordered_map<int, int> s;

int ans, n, mn, k;
int a[N];

#define lowbit(x) ((x)&(-x))

void add(int x, int v) {
	for (; x <= M; x += lowbit(x)) s[x] += v;
}

int ask(int x) {
	int ans = 0;
	for (; x; x -= lowbit(x)) ans += s[x];
	return ans;
}

signed main() {
	n = read(); k = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read() + a[i - 1] - k, mn = min(mn, a[i]), ans += a[i] >= 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = a[i] - mn + 1;
		ans += ask(a[i]); add(a[i], 1);
	} return printf("%lld\n", ans), 0;
}