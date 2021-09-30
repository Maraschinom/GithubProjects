#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

namespace io {
	int read(int x = 0, char ch = getchar(), bool f = false) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

int T, n, a, b, mod, ans, Mod;

using namespace io;

int qpow(int x, int y) {
	int ans = 1; x %= Mod;
	for (; y; y >>= 1, x = (1LL * x * x) % Mod) if (y & 1) ans = (1LL * ans * x) % Mod;
	return ans % Mod;
}

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

signed main() {
	fre(c);
	T = read();
	while (T--) {
		a = read(); b = read(); mod = read(); ans = 0; Mod = (mod << 1) + 1;
		for (int i = 0; i <= (mod << 1); ++i) {
			if (qpow(i, a) == b % Mod) ++ans;
		} printf("%d\n", ans);
	} return 0;
}