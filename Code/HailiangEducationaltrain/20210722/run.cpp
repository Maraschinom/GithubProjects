#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>

using namespace std;

namespace io {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using namespace io;

#define lowbit(x) ((x)&(-x))

const int N = 55;

int n, m, u, v;
int f[N][N][N], g[N][N];

#define fre(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout);

signed main() {
	memset(g,0x3f,sizeof g); 
	fre(run); n = read(); m = read();
	for (int i = 1; i <= m; ++i)
		u = read(), v = read(), f[0][u][v] = 1;
	for (int l = 1; l <= 31; ++l)
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j) f[l][i][j] |= f[l - 1][i][k] and f[l - 1][k][j];
	for (int l = 0; l <= 31; ++l)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if(f[l][i][j]) g[i][j] = 1; 
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
	printf("%d\n",g[1][n]);
}
