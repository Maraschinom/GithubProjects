/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-11 19:00:36
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-11 19:18:34
*/

#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 5e2 + 5, M = 4e6 + 5;

int n, m;
int t[N], f[N];
int cnt[M];

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) t[i] = read(), cnt[t[i]] = 1;
	sort(t + 1, t + 1 + n);
	for (int i = 1; i <= 4e6; ++i) cnt[i] += cnt[i - 1];
}