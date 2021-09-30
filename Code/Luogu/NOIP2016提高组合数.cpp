/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-17 18:57:34
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-17 19:55:16
*/

#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 2e3 + 5;

int T, n, m, mod;
int c[N][N], cnt[N][N], sum[N];

signed main() {
	T = read(); mod = read();

	c[0][0] = 1;
	for (int i = 1; i <= 2000; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
			if (!c[i][j]) ++ sum[j];
			cnt[i][j] = cnt[i][j - 1] + sum[j];
		}
	}

	while (T--) {
		n = read(), m = read();
		printf("%d\n", cnt[n][min(n, m)]);
	}

}