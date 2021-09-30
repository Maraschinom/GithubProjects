#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

namespace io {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

typedef long long LL;
typedef pair<int, int> PII;

#define int long long

using io::read;

const int N = 5e5 + 5;
int n, m, u, v, w, root, tot, mid, ans, sum, now, answer, tt;
int Siz[N], Mx[N], d[N], b[N], a[N], cnt[N];
bool vis[N];
vector<PII> Graph[N];
vector<int> F[N], G[N], go[N];

void get_root(int u, int fa) {
	Siz[u] = 1, Mx[u] = 0;
	for (auto v : Graph[u]) {
		int son = v.first;
		if (son == fa || vis[son]) continue;
		get_root(son, u);
		Siz[u] += Siz[son]; Mx[u] = max(Mx[u], Siz[son]);
	} Mx[u] = max(Mx[u], now - Siz[u]);
	if (Mx[u] < Mx[root]) root = u;
}

void get_dis(int u, int fa, int dis) {
	F[tot].emplace_back(dis);
	for (auto v : Graph[u]) {
		int son = v.first, w = v.second;
		if (vis[son] || son == fa) continue;
		get_dis(son, u, dis + w);
	}
} 

long long calc(int u, int t) {
	int l = 0, r = F[u].size() - 1; if (r <= 0) return 0;
	int sum = ((r + 1) * r) / 2;
	while (l < r) {
		if (F[u][l] + F[u][r] < t) {
			sum -= (r - l);
			--r;
		}
		else {
			++l;
		}
	} return sum;
}

void prepare(int u) {
	vis[u] = true, G[u].push_back(++tot), get_dis(u, 0, 0);
	for (auto v : Graph[u]) {
		int son = v.first;
		if (vis[son]) continue;
		G[u].emplace_back(++tot), get_dis(son, u, v.second);
		root = 0, now = Siz[son], get_root(son, u), go[u].emplace_back(root), prepare(root);
	}
}

void solve(int u, int t) {
	if (G[u].size()) answer += calc(G[u][0], t);
	for (int i = 1; i < (int)G[u].size(); ++i) answer -= calc(G[u][i], t);
	for (auto v : go[u]) solve(v, t);
}

int check(int t) {
	answer = 0; solve(tt, t);
	return answer;
}

bool cmp(int a, int b) {
	return a > b;
}

multiset<int> st;
priority_queue<int> Q;

void Find(int u) {
	if (G[u].size()) {
		for (auto v : F[G[u][0]]) if (v > ans) Q.push(v);
		if ((int)G[u].size() >= 2) {
			for (auto v : F[G[u][1]]) st.insert(-v);
		}
	}
	for (int i = 2; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		for (int j = 0; j < (int)F[v].size() && F[v][0] - *(st.begin()) > ans; ++j) {
			int p = F[v][j];
			for (multiset<int>::iterator it = st.begin(); it != st.end(); ++it) {
				if (p - (*it) <= ans) break;
				Q.push(p - (*it));
			}
		}
		for (auto g : F[v]) st.insert(-g);
	} st.clear();
	for (auto v : go[u]) Find(v);
}

#define fre(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout);

signed main() {
	fre(b); n = read(), m = read();
	for (int i = 1; i < n; ++i) {
		u = read(), v = read(), w = read();
		Graph[u].emplace_back(make_pair(v, w)), Graph[v].emplace_back(make_pair(u, w));
		sum += w;
	}
	Mx[root = 0] = now = n; get_root(1, 0); tt = root; prepare(root);
	for (int i = 1; i <= tot; ++i) sort(F[i].begin(), F[i].end(), cmp);
	int l = 0, r = sum; ans = 0;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid) >= 1LL * m) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	Find(tt); while ((int)Q.size() < m) Q.push(ans);
	while (!Q.empty()) printf("%lld\n", Q.top()), Q.pop();
	return 0;
}