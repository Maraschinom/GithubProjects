#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

int read(int x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e6 + 5;
int n, m, ans;
int a[N];
int l[N], r[N];
bool vis[N];

priority_queue<PII,vector<PII>,less<PII> > Q;

void del(int x) {
	int L = l[x], R = r[x];
	l[x] = 0, r[x] = 0, vis[x] = true;
	r[L] = R, l[R] = L; return;
}

void solve() {
	while (vis[Q.top().second]) Q.pop();
	int x = Q.top().second; Q.pop();
	ans += a[x]; a[x] = a[l[x]] + a[r[x]] - a[x];
	del(l[x]), del(r[x]);
	Q.push(make_pair(a[x], x));
}

signed main() {
	n = read(), m = read();
	if (m > n / 2) return puts("Error!"), 0;
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) l[i] = i - 1; l[1] = n;
	for (int i = 1; i <= n; ++i) r[i] = i + 1; r[n] = 1;
	for (int i = 1; i <= n; ++i) Q.push(make_pair(a[i], i));
	for (int i = 1; i <= m; ++i) solve();
	printf("%d\n", ans); return 0;
}
