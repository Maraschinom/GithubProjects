#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e2 + 5;

void max_to(int &a, int b) {a = max(a, b);}

void min_to(int &a, int b) {a = min(a, b);}

int n, ans;
int a[N];
char b[N];
int mx[N][N], mn[N][N];

signed main() {
	n = read();

	for (int i = 1; i <= (n << 1); ++i) {
		if (i & 1) {
			cin >> b[i + 1 >> 1];
			b[(i + 1 >> 1) + n] = b[i + 1 >> 1];
		}
		else a[i >> 1] = a[(i >> 1) + n] = read();
	}

	memset(mx, 128, sizeof mx); memset(mn, 0x3f, sizeof mn);

	for (int i = 1; i <= (n << 1); ++i)
		mx[i][i] = mn[i][i] = a[i];

	for (int len = 1; len <= n; ++len)
		for (int l = 1; l + len <= 2 * n; ++l) {
			int r = l + len;
			for (int k = l; k < r; ++k) {
				if (b[k + 1] == 'x') {
					max_to(mx[l][r], mx[l][k] * mx[k + 1][r]);
					max_to(mx[l][r], mn[l][k] * mn[k + 1][r]);

					min_to(mn[l][r], mn[l][k] * mn[k + 1][r]);
					min_to(mn[l][r], mx[l][k] * mn[k + 1][r]);
					min_to(mn[l][r], mn[l][k] * mx[k + 1][r]);
				} else {
					max_to(mx[l][r], mx[l][k] + mx[k + 1][r]);
					min_to(mn[l][r], mn[l][k] + mn[k + 1][r]);					
				}
			}
		}

	for (int i = 1; i <= n; ++i) max_to(ans, mx[i][i + n - 1]);

	printf("%d\n", ans);

	for (int i = 1; i <= n; ++i) if (mx[i][i + n - 1] == ans) printf("%d ", i);
}	