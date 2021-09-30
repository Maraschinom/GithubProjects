#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e4 + 5, M = 1e3 + 5;

int n, m, k, ans = 1e9, id;
int X[N], Y[N];
int dp[N][M];
bool vis[N];
bool flag = false;

struct node{
	int x;
	int up, down;
	node(): x(0), up(0), down(0) {}
	node(int _x, int u, int d): x(_x), up(u), down(d) {}
	friend bool operator < (const node a, const node b) {
		return a.x < b.x;
	}
}a[N];

signed main() {
	n = read(), m = read(), k = read();
	for (int i = 0; i < n; ++i) X[i] = read(), Y[i] = read();
	for (int i = 1, p, h, l; i <= k; ++i)
		p = read(), l = read(), h = read(),
		vis[p] = true, a[i] = node(p, h, l);
	sort(a + 1, a + 1 + k);
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= m; ++i) dp[0][i] = 0;
	for (int i = 1; i <= n; ++i)
		if (vis[i]) {
			++ id;	
			for (int j = a[id].down + 1; j < a[id].up; ++j) {
				if(j + Y[i - 1] <= m) dp[i][j] = min(dp[i - 1][j + Y[i - 1]], dp[i][j]);
				for (int k = 1; j - k * X[i - 1] >= 1; ++k)
					dp[i][j] = min(dp[i - 1][j - k * X[i - 1]] + k, dp[i][j]);
			}
		} else {
			for (int j = 1; j <= m; ++j) {
				if(j + Y[i - 1] <= m) dp[i][j] = min(dp[i - 1][j + Y[i - 1]], dp[i][j]);
				if (j == m)
					for (int k = 1; k <= m; ++k)
						dp[i][j] = min(dp[i - 1][k] + max(1,(int)ceil((m - k) * 1.0 / X[i - 1])), dp[i][j]);
				else
					for (int k = 1; j - k * X[i - 1] >= 1; ++k)
						dp[i][j] = min(dp[i - 1][j - k * X[i - 1]] + k, dp[i][j]);
			}
		}
	for (int i = 1; i <= k; ++i) {
		flag = false;
		for (int j = a[i].down + 1; j <= a[i].up ; ++j)
			if (dp[a[i].x][j] < 1e9) flag = true;
 		if (!flag) return printf("0\n%d\n", i - 1), 0;
	} puts("1");
	for (int i = 1; i <= m; ++i)
		ans = min(ans, dp[n][i]);
	return printf("%d\n", ans), 0;
}