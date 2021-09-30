#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e5 + 5;

int n, r;
int a[N];
int f[2][N][2];

signed main() {
	n = read(), r = read(); r = min(r, n - r);
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= r; ++j) {
			
		}
	}
}