#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

namespace io {
	int read(int x = 0, char ch = getchar(), bool f = false) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
};

using namespace io;

const int N = 1e5 + 5, W = 1e2;

int n, u, v, max_w;
int weight[N];
int f[N][2 * W + 5];

vector<int> G[N];

void dfs(int u, int fa) {
	bool leaf = true;
	for (auto v : G[u]) if (v != fa) dfs(v, u), leaf = false;
	if (leaf) {
		f[u][max_w + weight[u]] = 1, f[u][max_w - 1] = 0;
		for (int i = max_w - 1; i >= -max_w; --i) f[u][i + max_w] = min(f[u][i + max_w], f[u][i + max_w + 1]);
	}
	else {
		for (int i = -max_w; i < 0; ++i) {
			f[u][max_w + i] = 0;
			for (auto v : G[u]) if(v != fa) f[u][max_w + i] += f[v][max_w + i + 1];
		}
		for (int i = 0; i <= max_w; ++i) {
			int mn = 2147483647, sum = 0;
			for (auto v : G[u]) if (v != fa) sum += f[v][max_w - i];
			for (auto v : G[u]) if (v != fa) mn = min(mn, sum - f[v][max_w - i] + f[v][max_w + i + 1]);
			f[u][i + max_w] = mn;	
		}
		int sum = 1;
		for (auto v : G[u]) if(v != fa) sum += f[v][max_w - weight[u]];
		f[u][max_w + weight[u]] = min(f[u][max_w + weight[u]], sum); 
		for (int i = max_w - 1; i >= -max_w; --i) f[u][i + max_w] = min(f[u][i + max_w], f[u][i + max_w + 1]);
	}
}

signed main() {
	while (~scanf("%d", &n)) {
		memset(f, 0x3f, sizeof f); max_w = 0;
		for (int i = 1; i <= n; ++i) G[i].clear();
		for (int i = 1; i <= n; ++i) max_w = max(max_w, weight[i] = read());
		for (int i = 1; i < n; ++i) u = read(), v = read(), G[u].push_back(v), G[v].push_back(u); 
		dfs(1, 0); printf("%d\n", f[1][max_w]); 
	}
}