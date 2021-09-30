#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 6;

int n;
int g[N];
int f[30][30][30][30][30];

signed main() {
	while(n = read()) {
		memset(g, 0, sizeof g);
		for (int i = 1; i <= n; ++i) g[i] = read();
		memset(f, 0, sizeof f);
		f[0][0][0][0][0] = 1;
		for (int a = 0; a <= g[1]; ++ a)
			for (int b = 0; b <= min(g[2], a); ++ b)
				for (int c = 0; c <= min(g[3], b); ++ c)
					for (int d = 0; d <= min(g[4], c); ++ d)
						for (int e = 0; e <= min(g[5], d); ++ e) {
							if (a && a > b) f[a][b][c][d][e] += f[a - 1][b][c][d][e];
							if (b && b > c) f[a][b][c][d][e] += f[a][b - 1][c][d][e];
							if (c && c > d) f[a][b][c][d][e] += f[a][b][c - 1][d][e];
							if (d && d > e) f[a][b][c][d][e] += f[a][b][c][d - 1][e];
							if (e) f[a][b][c][d][e] += f[a][b][c][d][e - 1];
						}
		printf("%lld\n", f[g[1]][g[2]][g[3]][g[4]][g[5]]);
	} return 0;
}