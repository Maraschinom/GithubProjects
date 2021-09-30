#include <iostream>
#include <cstdio>

using namespace std;

int k;

void out_two_bridge(int x, int y,int n) {
	printf("%d %d\n", x, y);
	printf("%d %d\n", x + (n >> 1), y + (n >> 1));
	return void();
}

signed main() {
	cin >> k;
	if ((k + 1) & 1) return puts("NO"), 0;
	puts("YES");
	int n = 4 * k - 2;
	int m = n * k >> 1;
	printf("%d %d\n%d %d\n", n, m, 1, (n >> 1) + 1);
	for (int i = 2; i <= k; ++i) out_two_bridge(1,i,n);
	for (int i = 2; i <= k; ++i) for (int j = k + 1; j <= 2 * k - 1; ++j)
		out_two_bridge(i,j,n);
	for (int i = k + 1; i <= (k << 1) - 1; i += 2) out_two_bridge(i,i + 1,n);
	return 0;
}