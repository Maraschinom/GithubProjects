#include <iostream>
#include <cstdio>

using namespace std;

void write(int x) {
	if (x & 1) puts("4 * 2 = 8\n3 * 5 = 15\n1 + 8 = 9\n9 + 15 = 24");
	else puts("1 * 2 = 2\n3 * 4 = 12\n2 * 12 = 24");
}

signed main() {
	int n;
	cin >> n;
	if (n < 4) puts("NO");
	else {
		puts("YES");
		int round = (n - 4) / 2;
		if (n & 1) {
			write(5);
			for (int i = 6; i <= n; i += 2) printf("%d - %d = 1\n", i + 1, i);
		}
		else {
			write(4);
			for (int i = 5; i <= n; i += 2) printf("%d - %d = 1\n", i + 1, i);
		}
		for (int i = 1; i <= round; ++i) puts("24 * 1 = 24");
	}
}