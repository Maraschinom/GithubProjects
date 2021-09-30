#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 2e3 + 5;

int n, m, C, ans, u, v;
vector<int> G[N];

void dfs(int x, int T, int sum) {
	if (x == 1) ans = max(sum - T * T * C, ans);
	for (auto y : G[x]) {
		dfs(y, T + 1, sum + m[y]);
	}
}

signed main() {
	n = read(), m = read(), C = read();
	for (int i = 1; i <= m; ++i) 
	return 0;	
}
