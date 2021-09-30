#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e6 + 5;

int n, ans, r; int a[N]; PII b[N], sec[N];

signed main() {
	n = read();
	for (int i = 1; i <= n; ++i) 
		a[i] = b[i].first = read(), b[i].second = i;
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; ++i) 
		sec[i].first = i, sec[b[i].second].second = i;
	for (int i = 1; i <= n; ++i)
		if (sec[i].first > sec[i].second) swap(sec[i].first, sec[i].second);
	sort(sec + 1, sec + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (sec[i].first > r) ++ ans;
		r = max(r, sec[i].second);
	} return printf("%d\n", ans), 0;
}