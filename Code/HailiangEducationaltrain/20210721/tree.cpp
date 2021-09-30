#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

namespace io {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using namespace io;

const int N = 2e4 + 5;
int T, n;
int f[N], Siz[N];
long long ans;

int get(int x) { return x == f[x] ? x : f[x] = get(f[x]); }

class Edge {
	public:
		int fr, to, val;
};

Edge E[N];

bool operator <(Edge a, Edge b) {
	return a.val < b.val;
}

signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	T = read();
	while (T--) {
		n = read(); ans = 0;
		for (int i = 1; i < n; ++i)
			E[i].fr = read(), E[i].to = read(), E[i].val = read();
		for (int i = 1; i <= n; ++i) f[i] = i, Siz[i] = 1;
		sort(E + 1, E + n);	
		for (int i = 1; i < n; ++i) {
			int _f = get(E[i].fr), ff = get(E[i].to);
			if (_f == ff) continue;
			ans += 1LL * E[i].val + 1LL * (Siz[_f] * Siz[ff] - 1LL) * (E[i].val + 1LL);
			f[_f] = ff;
			Siz[ff] += Siz[_f];
		} printf("%lld\n", ans);
	}
}