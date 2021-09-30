#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 205;

int n, lena, lenb, ansa, ansb;

int a[N], b[N];

signed main(int argc, char *argv[]) {
	
	// 0 剪刀 1 石头 2 布 3 蜥蜴人 4 斯波克

	// 剪刀输给石头和斯波克 0 -> 1 4

	// 石头输给布和斯波克 1 -> 2 4

	// 布输给剪刀和蜥蜴人 2 -> 0 3

	// 蜥蜴人输给剪刀和石头 3 -> 0 1

	// 斯波克输给布和蜥蜴人 4 -> 2 3

	freopen("rps.in", "r", stdin);
	freopen("rps.out", "w", stdout);

	n = read(), lena = read(), lenb = read();

	for (int i = 1; i <= lena; ++i) a[i] = read();
	for (int i = 1; i <= lenb; ++i) b[i] = read();

	for (int i = 1; i <= n; ++i) {
		int x = a[(i - 1) % lena + 1];
		int y = b[(i - 1) % lenb + 1];

		if (x != y) {
			if (!x) {
				if (y == 1 || y == 4) ++ ansb;
				else ++ ansa;
			} else if (x == 1) {
				if (y == 2 || y == 4) ++ ansb;
				else ++ ansa;
			} else if (x == 2) {
				if (!y || y == 3) ++ ansb;
				else ++ ansa;
			} else if (x == 3) {
				if (!y || y == 1) ++ ansb;
				else ++ ansa;
			} else if (x == 4) {
				if (y == 2 || y == 3) ++ ansb;
				else ++ ansa;
			}
		}

	} return printf("%d %d\n", ansa, ansb), 0;
}