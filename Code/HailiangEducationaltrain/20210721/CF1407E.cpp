#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

namespace io {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using io::read;

const int N = 5e5 + 5;
int n, m, u, v, w;
int dis[N], color[N];
vector<pair<int, int>> G[N];
bool vis[N];

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= m; ++i) {
		u = read(), v = read(), w = read();
		G[v].push_back(make_pair(u, w));
	} queue<int> Q; Q.push(n);
	memset(color, -1, sizeof color); memset(dis, 0x3f, sizeof dis);
	dis[n] = 0; color[n] = 0;
	while (Q.size()) {
		int u = Q.front(); Q.pop(); vis[u] = true;
		for (auto it : G[u]) {
			int v = it.first, col = it.second; if (vis[v]) continue;
			if (!~color[v])
				color[v] = 1 - col;
			else
				if (color[v] == col && dis[v] > dis[u] + 1)
					dis[v] = dis[u] + 1, Q.push(v);
		}
	} printf("%d\n", dis[1] == 1061109567 ? -1 : dis[1]);
	for (int i = 1; i <= n; ++i) printf("%d", max(0, color[i])); return 0;
}