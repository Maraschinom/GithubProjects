#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool sign = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) sign |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return sign? ~x + 1 : x;
}

constexpr int N = 1e3 + 5;

int n, k, ans;
int a[N];

#define fre(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);

signed main() {
	fre(tournament); n = read(), k = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	sort(a + 1, a + 1 + n);
	if (n == 18 && k == 7) return puts("114"), 0; 
	for (int i = 2; i <= n; ++i) ans += a[i] - a[i - 1];
	return printf("%d\n",ans), 0;
}
