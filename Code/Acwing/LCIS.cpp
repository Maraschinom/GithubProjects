#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? ~x + 1 : x; 
} 

const int N = 3005;

int T;
int n, m, tot, ans, fr;
int b[N], a[N];
int f[N][N];

signed main() {
	T = 1;
	while (T--) {
		memset(f, 0, sizeof f);
		ans = 0;
		n = read(); a[0] = 2147483647;
		for (int i = 1; i <= n; ++i) a[i] = read();
		m = read(); b[0] = 2147483647;
		for (int i = 1; i <= m; ++i) b[i] = read();
		for (int i = 1; i <= n; ++i) {
			fr = 0;
			for (int j = 1; j <= m; ++j) {
				f[i][j] = f[i - 1][j];
				if (a[i] == b[j])
					f[i][j] = max(f[i - 1][fr] + 1, f[i][j]); 
				if (a[i] > b[j]) if (f[i - 1][fr] < f[i - 1][j]) fr = j;
			}
		}
		for (int i = 1; i <= m; ++i)
			ans = max(f[n][i], ans);
		printf("%d\n", ans);
		if (T) puts("");
	}
}
