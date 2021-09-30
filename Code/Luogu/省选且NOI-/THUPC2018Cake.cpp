/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-17 19:57:03
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-17 20:58:21
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int mod = 2148473648;

int T;
int a[10], ans[10];

void dfs(int dim, int dye, int num) {
	if (dim > 4) {
		ans[dye] = (ans[dye] + num) % mod;
		return;
	}
	if (a[dim] == 1) {
		dfs(dim + 1, dye + 2, num);
		return;
	}
	dfs(dim + 1, dye + 1, (num + num) % mod);
	dfs(dim + 1, dye, (1ll * num * (a[dim] - 2)) % mod);
}

signed main() {
	T = read();
	while (T--) {
		memset(ans, 0, sizeof ans);
		for (int i = 1; i <= 4; ++i) a[i] = read();
		dfs(1, 0, 1); for (int i = 0; i <= 8; ++i) printf("%lld ", ans[i]);
		puts("");
	} return 0;
}