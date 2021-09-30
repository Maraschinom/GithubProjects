#include <bits/stdc++.h>

using namespace std;

const int M = 5050, N = 105;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

int n, m, k;

namespace Float{
	__float128 dp[2][2 * M + 5][N][3];
};

namespace Double{
	long double dp2[2][2 * M + 5][N][3];
};

const long double eps = 1e-14;

template<class T>
void output(T ans) {
	if (ans + eps >= 1) cout << "1." << string(k, '0') << endl;
	else {
		printf("0.");
		ans *= 10;
		for (int i = 1; i <= k; ++i)
			printf("%d", (int)(ans + (i == k) * 0.5)),
			ans = (ans - (int)ans) * 10;
	}
}

template<class T>
void solve(T f[][2 * M + 5][N][3]) {
	f[0][M][0][0] = 1;
	int now = 1;
	for (int i = 1; i <= n; ++i) {
		memset(f[now], 0, sizeof f[now]);
		for (int j = 0; j <= 2 * M; ++j)
			for (int k = 0; k < i; ++k)
				for (int l = 0; l < 3; ++l) {
					if (!f[now ^ 1][j][k][l]) continue;
					if (j - 2 * i >= 0) f[now][j - 2 * i][k + 1][l] += f[now ^ 1][j][k][l] * (k - l + 1) / i;
					if (k) f[now][j][k][l] += f[now ^ 1][j][k][l] * (2 * k - l) / i;
					if (j + 2 * i <= 2 * M) f[now][j + 2 * i][k - 1][l] += f[now ^ 1][j][k][l] * (k - 1) / i;
					if (l < 2) {
						if (j + i <= 2 * M) f[now][j + i][k][l + 1] += f[now ^ 1][j][k][l] * (2 - l) / i;
						if (j - i >= 0) f[now][j - i][k + 1][l + 1] += f[now ^ 1][j][k][l] * (2 - l) / i;
					}
				}
		now ^= 1;
	}
	T ans = 0;
	for (int i = M + m; i <= 2 * M; ++i) ans += f[n & 1][i][1][2];
	output(ans);
}

int main() {
	n = read(), m = read(), k = read();
	if (k <= 8) solve(Double::dp2);
	else solve(Float::dp);
	return 0;
}