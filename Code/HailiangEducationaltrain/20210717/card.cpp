#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

typedef long long LL;
#define unordered_map map
#define fre(x) freopen(#x".in","r",stdin); freopen(#x".out", "w", stdout) ;
const int N = 105;

int T, n;
int a[N];

unordered_map<int, unordered_map<int, bool> > win;
unordered_map<int, unordered_map<int, double> > f;

int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}

int solve1(int x, int y) {
	if (y == n) return 0;
	if (win.count(x) && win[x].count(y)) return win[x][y];
	win[x][y] = 0;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) if (gcd(a[i],x) == x) ++cnt;
	if (y < cnt && !solve1(x, y + 1)) win[x][y] = true;
	for (int i = 1; i <= n; ++i) {
		int _gcd = gcd(x, a[i]);
		if (_gcd != 1 && _gcd != x) {
			if (!solve1(_gcd, y + 1)) {
				win[x][y] = true;
				break;
			}
		}
	}
	return win[x][y];
}

double solve2(int x, int y) {
	if (y == n) return 0.0;
	if (f.count(x) && f[x].count(y)) return f[x][y];
	f[x][y] = 0.0;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) if (gcd(a[i], x) == x) ++cnt;
	double P = 0.0;
	if (y < cnt) P += 1.0 * (cnt - y) / (n - y) * (1.0 - solve2(x, y + 1));
	for (int i = 1; i <= n; ++i) {
		int _gcd = gcd(x, a[i]);
		if (_gcd != 1 && _gcd != x) {
			P += 1.0 / (n - y) * (1.0 - solve2(_gcd, y + 1));
		}
	}
	return f[x][y] = P;
}

signed main(int argc, char *argv[]) {
	fre(card); T = read();
	while (T--) {
		n = read();
		win.clear(), f.clear();
		for (int i = 1; i <= n; ++i) a[i] = read();
		printf("%d ", solve1(0, 0));
		printf("%.4lf\n", solve2(0, 0));
	} return 0;
}
