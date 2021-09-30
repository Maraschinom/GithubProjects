 #include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>

using namespace std;

namespace io {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using namespace io;

const int N = 1e2, S = 1 << 11;
int n, m, d, u, v, w, ans;
bitset<N> f[S],g[S],V[2][S];

#define fre(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout);

signed main() {
	fre(y); n = read(), m = read(), d = read();
	int d2 = d / 2, d1 = d - d2; 
	for (int i = 1; i <= m; ++i) {
		u = read(), v = read(), w = read();
		V[w][u][v] = 1, V[w][v][u] = 1;			
	}
	for (int i = n; i; --i) {
		for (int j = 0; j < S; ++j) f[j].reset();
		f[1][i] = 1;
		for (int j = 1; j < 1 << d1; ++j)
			for (int k = 1; k <= n; ++k)
				if (f[j][k])
					f[j << 1] |= V[0][k],	
					f[j << 1 | 1] |= V[1][k];
		for (int j = 0; j < 1 << d1; ++j)
			g[j][i] = f[1 << d1 | j].any();
	}
	for (int i = 0; i < 1 << d1; ++i)
		for (int j = 0; j < 1 << d2; ++j)
			if ((f[1 << d2 | j] & g[i]).any()) ++ ans;	
	printf("%d\n", ans);
}
