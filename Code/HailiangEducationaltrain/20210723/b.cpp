#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace io {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using io::read;

const int N = 5e4 + 5;
int n, m, u, v, w, root, tot, mid, ans;
int Siz[N], Mx[N], d[N], b[N], a[N], cnt[N];
int aa[N];
bool vis[N];
vector<pair<int,int>> G[N];
vector<int> answer;
unordered_map<int, unordered_map<int, int>> dis;

void get_root(int u,int fa,int siz) {
	Siz[u] = 1, Mx[u] = 0;
	for (auto v : G[u]) {
		int son = v.first;
		if (son == fa || vis[son]) continue;
		get_root(son, u, siz);
		Siz[u] += Siz[son]; Mx[u] = max(Mx[u], Siz[son]);
	} Mx[u] = max(Mx[u], siz - Mx[u]);
	if (!root || Mx[u] < Mx[root]) root = u;
}

void get_dis(int u, int fa, int dis, int rt) {
	d[u] = dis; b[u] = rt; a[++tot] = u;
	for (auto v : G[u]) {
		int son = v.first, w = v.second;
		if (vis[son] || son == fa) continue;
		get_dis(son, u, dis + w, rt);
	}
}

bool compare(int a,int b) {
	return d[a] < d[b];
}

void calc(int rt) {
	tot = 0;
	a[++tot] = rt;
	d[rt] = 0; b[rt] = rt;
	for (auto v : G[rt]) {
		int son = v.first;
		if (vis[son]) continue;
		get_dis(son, rt, v.second, rt);
	}
	sort(a + 1, a + 1 + tot, compare);
	int l = 1, r = tot;
	while (l < r) {
		if (d[a[l]] + d[a[r]] > mid) {
			--r; --cnt[b[a[r]]];
		}
		ans += r - l - cnt[b[a[l]]];
		++l; --cnt[b[a[l]]];
	}
}

void solve(int rt) {
	vis[rt] = true; calc(rt);
	for (auto v : G[rt]) {
		int son = v.first;
		if (vis[son]) continue;
		root = 0;
		get_root(son, -1, Siz[son]);
		solve(root);
	}
}

void dfs(int st,int u, int fa) {
	for (auto v : G[u]) {
		int son = v.first;
		if (son == fa) continue;
		answer.emplace_back(dis[st][son] = dis[st][u] + v.second);
		dfs(st, son, u);
	}
}

#define fre(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout);

signed main(int argc, char *argv[]) {
	fre(b); n = read(), m = read();
	for (int i = 1; i < n; ++i) {
		u = read(), v = read(), w = read();
		G[u].emplace_back(make_pair(v,w)), G[v].emplace_back(make_pair(u,w));
	}
	for (int i = 1; i <= n; ++i) {
		dfs(i, i, -1);
	} sort(answer.begin(), answer.end(), greater<int>());
	for (int i = 1; i <= 2 * m; i += 2) {
		printf("%d\n", answer[i - 1]);
	}
	//Mx[0] = 0;
	//get_root(1, -1, n);
	//solve(root);
	//printf("%d\n", ans);
	return 0;
}
/*
5 10
1 2 1
1 3 2
2 4 3
2 5 4
*/