/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-10 20:15:32
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-10 20:24:20
*/

#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? ~x + 1 : x;
}

const int N = 12, M = 1 << 12;

int n, m;
int f[N][M];
bool s[M];

signed main() {
	while(n = read(), m = read()) {
		if (!(n | m)) break;
		for (int i = 0; i < 1 << n; ++i) {
			s[i] = true;
			int cnt = 0;
			for (int j = 0; j < n; ++j) {
				if (i >> j & 1) {
					if (cnt & 1) s[i] = false;
					cnt = 0;
				} else {
					++ cnt;
				}
			}
			if(cnt & 1) s[i] = false;
		}

		memset(f, 0, sizeof f);

		f[0][0] = 1;

		for (int i = 1; i <= m; ++i) {
			for (int j = 0; j < 1 << n; ++j) {
				for (int k = 0; k < 1 << n; ++k) {
					if (!(j & k) && s[j | k]) f[i][k] += f[i - 1][j];
				}
			}
		} printf("%d\n", f[m][0]); 
	}
}