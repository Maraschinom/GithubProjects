/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-17 16:05:29
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-17 16:28:29
*/

#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 11;

int n, res, cnt;
int ans[N];
int vec[N][5];

#define sqr(x) (x)*(x)

signed main() {
	n = read(); if (n > 11) {return puts("0"), 0;}
	for (int i = 1; i <= n; ++i) 
		for (int j = 0; j < 5; ++j) vec[i][j] = read();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			if (i ^ j) for (int k = j + 1; k <= n; ++k) if (i ^ k) {
				res = 0;
				for (int t = 0; t < 5; ++t) res += (vec[i][t] - vec[j][t]) * (vec[i][t] - vec[k][t]);
				if (res > 0) goto end;
			}
		ans[++ cnt] = i;
		end:;
	} printf("%d\n", cnt);
	for (int i = 1; i <= cnt; ++i) printf("%d ", ans[i]);
	return 0;
}