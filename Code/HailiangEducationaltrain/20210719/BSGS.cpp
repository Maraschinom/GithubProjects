#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <unordered_map>

using namespace std;

#define int long long

namespace io {
	int read(int x = 0, char ch = getchar(), bool f = false) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using io::read;

int a, b, p;

unordered_map<int, int> Hash_tab;

int qpow(int x, int y, int mod) {
	int ans = 1;
	for (; y; y >>= 1, x = (1LL * x * x) % mod) if (y & 1) ans = (1LL * ans * x) % mod;
	return ans % mod;
}

int min_log_mod(int a,int b,int p) {
	Hash_tab.clear();
	int Pow = b % p;
	int Size = (int)ceil(sqrt(p));
	int v = qpow(a,Size,p);
	Hash_tab[Pow] = 0;
	for (int i = 1; i <= Size; ++i) {
		Pow = (1LL * Pow * a) % p;
		Hash_tab[Pow] = i;
	} Pow = 1;
	for (int i = 1; i <= Size; ++i) {
		Pow = (Pow * v) % p;
		if (Hash_tab.count(Pow)) return ((i * Size - Hash_tab[Pow]) % p + p) % p;
	} return -1;
}

signed main() {
	p = read(); a = read(); b = read();
	if (!(a%p)) return printf("no solution"),0;
	int ans = min_log_mod(a, b, p);
	if (!(~ans)) puts("no solution");
	else printf("%lld\n", ans);
	return 0;
}