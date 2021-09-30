/*
* * * * * * * * * *
 @Author : Mukrus
 @Date : 2021-7-14
* * * * * * * * * *

我一直埋头于遗忘的海洋

*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;

int read(int x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 5e2 + 5, inf = 2147483647;
int n, m, ans;
int a[N] ;
int f[N][N];

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define max_to(x,y) x = max(x,y)

signed main(int argc, char* argv[]) {
	fre(b);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	ans = -inf;
	for (int i = 2; i < n; ++i) a[i] += a[i - 1];
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			f[i][j] = -1e9;
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = m - 1; ~j; --j)
			for (int k = 1 - (j == 0); k <= j; ++k) {
				max_to(f[j + 1][k], f[j][k]),
				max_to(f[j + 1][k + 1], f[j][k] + a[n] - 2 * a[i - 1]);
				if (k) max_to(f[j + 1][k - 1], f[j][k] + a[n] + 2 * a[i - 1]);
			}
		max_to(ans, f[m][0]);
	}
	printf("%d\n", ans);
	return 0;
}
/*
Input:
4 2
1 1 -1 1
Output:
6
*/
