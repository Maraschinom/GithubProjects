#include <iostream>
#include <cstdio>

using namespace std;

long long inf = 1e18 + 1, n, l, r;

signed main() {
	scanf("%lld", &n);
	l = n - inf % n * 9 % n * 9 % n; r = inf + l - 1;
	return printf("%lld %lld\n", l, r), 0;
}