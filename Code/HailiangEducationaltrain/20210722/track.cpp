
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define int long long

namespace io {
	int read(int x = 0, char ch = getchar(), bool f = false) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using io::read;

const int N = 1e3 + 5, Mod = 1e9 + 7;
int T, n, m, X, u, v, ans, cnt,matching_rate, subscript, w;
long long dis[N][1 << 8];
double mx;
double Ln[N][1 << 8];

class Edge {
public:
	int u, v, w, s;
	Edge(int _a, int _b, int _c, int _d) : u(_a), v(_a), w(_c), s(_d) {}
};

class Node {
public:
	int x, Matching;
	double Ln;
	Node(int _a, int _b, double _c) : x(_a), Matching(_b), Ln(_c) {}
	friend bool operator < (const Node &a, const Node &b) {
		return a.Ln > b.Ln;
	}
};
int prime[N], num[N];
vector<Edge> G[N];
unordered_map<int, bool> Vis;
bool vis[N][1 << 8];

#define fre(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout);

signed main() {
	/*fre(track);*/ T = read();
	while (T--) {
		Vis.clear();
		n = read(), m = read(), X = read();
		int p = X;
		for (int i = 2; i * i <= p; ++i) if(!(p % i)) {
			prime[++cnt] = i, num[cnt] = 0;
			while (p % i == 0) {
				p /= i;
				++num[cnt];
			}
		} if (p > 1) prime[++cnt] = p, num[cnt] = 1;
		for (int i = 1; i <= n; ++i) G[i].clear();
		for (int i = 1; i <= m; ++i) {
			u = read(), v = read(), w = read();
			if (X % w) continue;
			matching_rate = 0;
			for (int j = 1; j <= cnt; ++j) {
				int s = 0;
				while (w % prime[j] == 0) {
					++s;
					w /= prime[j];
				}
				if (s == num[j]) matching_rate |= 1 << j - 1;
			}
			G[u].emplace_back(Edge(u, v, w, matching_rate)),
			G[v].emplace_back(Edge(v, u, w, matching_rate));
		} memset(vis, 0, sizeof vis); memset(Ln, 127, sizeof Ln); priority_queue<Node> Q;
		for (int i = 1; i <= n; ++i) Ln[i][0] = 0, dis[i][0] = 1, Q.push(Node(i, 0, 0));
		while (!Q.empty()) {
			Node u = Q.top(); Q.pop();
			if (vis[u.x][u.Matching]) continue; vis[u.x][u.Matching] = true;
			for (auto v : G[u.x]) {
				double ln = log(v.w);
				if (Ln[v.v][u.Matching | v.s] > Ln[u.x][u.Matching] + ln) {
					Ln[v.v][u.Matching | v.s] = Ln[u.x][u.Matching] + ln;
					dis[v.v][u.Matching | v.s] = 1LL * dis[u.x][u.Matching] * v.w % Mod;
					Q.push(Node(v.v, u.Matching | v.s, Ln[v.v][u.Matching | v.s]));
				}
			}
		} ans = 0, mx = 1e12;
		for (int i = 1; i <= n; ++i) {
			if (Ln[i][(1 << cnt) - 1] < mx) {
				mx = Ln[i][(1 << cnt) - 1];
				ans = dis[i][(1 << cnt) - 1];
			}
		} if (mx == 1e12) puts("-1");
		else printf("%lld\n", ans);
	}
	return 0;
}
/*
1
5 6 56
5 1 2
5 1 1
3 5 8
1 2 14
5 2 1
2 1 2
*/