/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-11 20:21:59
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-11 20:51:16
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 2e5 + 5;

int n, m, u, v, w, cnt, ans;
int f[N], lst[N];

struct edge{
	int u, v, w;
	friend bool operator < (edge a, edge b) {return a.w < b.w;}
}E[N];

int find(int u) {
	return f[u] == u ? u : f[u] = find(f[u]);
}

void kruskal() {
	sort(E + 1, E + 1 + cnt);
	for (int i = 1; i <= cnt; ++i) {
		int x = find(E[i].u), y = find(E[i].v);
		if (x == y) ans += max(E[i].w, 0ll);
		else f[x] = y;
	}
}

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 1; i <= m; ++i) {
		u = read(), v = read(), w = read();
		E[++ cnt].u = u, E[cnt].v = v, E[cnt].w = w;
	} kruskal();
	return printf("%lld\n", ans), 0;
}