/*
* * * * * * * * * *
 @Author : Mukrus
 @Date : 2021-7-14
* * * * * * * * * *

无声的告别是对往事的礼赞

*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

#define int long long 

typedef long long LL;
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

LL read(LL x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e5 + 5;
LL n, ans, idx;
LL a[N], f[N], g[N];
char opt[N];

signed main(int argc, char* argv[]) {
	fre(a);
	n = read();
	a[1] = read(); f[1] = a[1];
	for (int i = 2; i <= n; ++i) {
		opt[i] = getchar(); a[i] = read();
		f[i] = f[i - 1] + (opt[i] == '+' ? a[i] : -a[i]);
	}
	LL ans = f[n], idx = n + 1;
	for (int i = n; i; --i) {
		g[i] = g[i + 1] + a[i];
		if (opt[i] == '-') {
			ans = max(ans, f[i - 1] + 2LL * g[idx] - g[i]);
			idx = i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
/*
Input:
3
3 - 5 - 5
Output:
3
*/
