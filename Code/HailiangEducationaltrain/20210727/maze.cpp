#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool sign = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) sign |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return sign ? ~x + 1 : x;
}

const int N = 1e5 + 5;

int n, m, k;
int x[N], y[N];
double ans = -1e9;

double calc(int a, int b) {
	return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

#define fre(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); 

signed main() {
	fre(maze); n = read(), m = read(), k = read();
	for (int i = 1; i <= k; ++i) x[i] = read(), y[i] = read();
	for (int i = 1; i <= k; ++i)
		for (int j = 1; j <= k; ++j) if (i != j)
			ans = max(ans, calc(i, j));
	for (int i = 1; i <= k; ++i)
		ans = max(ans, 1.0 * min(m - y[i], y[i]));
	return printf("%.8lf\n", ans / 2.), 0;
}
