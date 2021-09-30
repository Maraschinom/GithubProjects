/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-11 19:11:20
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-11 19:51:27
*/

#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e5 + 5;

int n, ans, tot, cnt;
int a[N], s[N];
int G[N], G2[N];

signed main() {
	n = read();
	for (int i = 1; i <= n; ++i) s[i] = (a[i] = read()) + s[i - 1];
	if (s[n] % 3 || n < 3) {return puts("0"), 0;}
	int x = s[n] / 3;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == x) G[++ cnt] = i;
		else if (s[i] == x << 1) G2[++ tot] = i;		
	}
	for (int i = 1; i <= cnt; ++i) {
		int v = G[i];
		int j = lower_bound(G2 + 1, G2 + 1 + tot, v) - 	1 - G2;
		ans += cnt - j;
	} return printf("%d\n", ans), 0;
}
/*
4
1 2 3 3
*/