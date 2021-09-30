/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-12 19:44:19
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-13 18:29:19
*/

#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 3e3 + 5, M = 3e2 + 5;

int n, m;
int x[N];
int f[N][M], w[N][M];

int cost(int l, int r) {
	int mid = l + r >> 1, ans = 0;
	for (int i = l; i < mid; ++i) ans += x[mid] - x[i];
	for (int i = mid + 1; i <= r; ++i) ans += x[i] - x[mid];
	return ans;
}

void pre() {
	for (int i = 1; i <= n; ++i) {
		w[i][i] = 0;
		for (int j = i + 1; j <= n; ++j) w[i][j] = w[i][j - 1] + x[j] -  x[i + j >> 1];
	}
}

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) x[i] = read(); pre();
	sort(x + 1, x + 1 + n); memset(f, 0x3f, sizeof f); f[0][0] = 0;
	for (int j = 1; j <= m; ++j)
		for (int i = 1; i <= n; ++i)
			for (int k = 0; k < i; ++k)
				f[i][j] = min(f[i][j], f[k][j - 1] + w[k + 1][i]);
	printf("%d\n", f[n][m]);
	return 0;
}