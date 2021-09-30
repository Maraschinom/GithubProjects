/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-11 20:11:52
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-11 20:19:42
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int n, ans;
int x[N], y[N];

map<pair<int, int>, int> f, vis;

signed main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
	for (int i = 1; i <= n; ++i) f[make_pair(x[i], y[i])] = i;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (f[make_pair(x[i], y[j])] && f[make_pair(x[j], y[i])]) {
				int a = f[make_pair(x[i], y[j])], b = f[make_pair(x[j], y[i])];
				if (a == i || a == j || b == i || b == j) continue;
				if (vis[make_pair(a, b)]) continue;
				vis[make_pair(a, b)] = 1;
				++ ans;
			}
		}
	} return printf("%d\n", ans >> 1), 0;
}