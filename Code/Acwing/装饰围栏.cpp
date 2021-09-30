#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? ~x + 1 : x;
}

const int N = 21;

int T, n, m;
int f[N][N][2];
bool vis[N];

signed main() {
	f[1][1][1] = f[1][1][0] = 1;
	for (int i = 2; i < N; ++i)
		for (int j = 1; j <= i; ++j) {
			for (int k = j; k <= i - 1; ++k) f[i][j][0] += f[i - 1][k][1];
			for (int k = 1; k <= j - 1; ++k) f[i][j][1] += f[i - 1][k][0];
		} T = read();
	while (T--) {
		n = read(); m = read();
		memset(vis, 0, sizeof vis); int lst, tmp;
		for (int i = 1; i <= n; ++i) {
			if (f[n][i][1] >= m) {
				lst = i, tmp = 1;
				break;
			}
			else m -= f[n][i][1];
			if (f[n][i][0] >= m) {
				lst = i, tmp = 0;
				break;
			}
			else m -= f[n][i][0];
		} vis[lst] = true;
		printf("%lld", lst);
		for (int i = 2; i <= n; ++i) {
			int j = 0; tmp ^= 1;
			for (int t = 1; t <= n; ++t) {
				if (vis[t]) continue; ++ j;
				if ((!tmp && t < lst) || (tmp && t > lst)) {
					if (f[n - i + 1][j][tmp] >= m) {
						lst = t; break;
					} else m -= f[n - i + 1][j][tmp];
				}
			}
			vis[lst] = true;
			printf(" %lld", lst);
		}
		puts(""); 
	} return 0;
}
