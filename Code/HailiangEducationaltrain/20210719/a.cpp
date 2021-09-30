#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <utility>
#include <algorithm>

using namespace std;

namespace io {
	int read(int x = 0, char ch = getchar(), bool f = false) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
};

using namespace io;

const int N = 1e6 + 5, maxn = 1e6;

int T, n, prime_count;
int prime[N], mobius[N];
bool mark[N];
long long ans;

void Mobius() {
	mobius[1] = 1;
	for (int i = 2; i <= maxn; ++i) {
		if (!mark[i]) prime[++prime_count] = i, mobius[i] = -1;
		for (int j = 1; j <= prime_count && prime[j] * i <= maxn; ++j) {
			mark[i * prime[j]] = 1;
			if (i % prime[j] == 0) { mobius[i * prime[j]] = 0; break; }
			else mobius[i * prime[j]] = -mobius[i];
		}
	}
}

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

long long f[N], g[N];

signed main() {
	fre(a);
	T = read(); Mobius();
	for (int i = 1; i <= maxn; ++i)
		for (int j = i; j <= maxn; j += i)
			f[j] += 1LL * mobius[i] * i ;
	for (int i = 1; i <= maxn; ++i)
		for (int j = i; j <= maxn; j += i)
			g[j] += j * 1LL * (j / i) * (j / i + 1) * f[i] / 2 ; 
	while (T--) {
		n = read(); printf("%lld\n",g[n]) ;
	} return 0;
}