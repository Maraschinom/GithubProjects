#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e7 + 5;

int n;
long long ans1, ans2;
int tr[N][2];
vector<int> a;

void build(int n) {
	vector<int> st(n + 1); int top = 0;
	for (int i = 1; i <= n; ++i) {
		while (top && a[st[top]] > a[i]) tr[i][0] = st[top --];
		if (st[top]) tr[st[top]][1] = i;
		st[++ top] = i;
	}
}

signed main() {
	n = read(); a.resize(n + 1); 
	for (int i = 1; i <= n; ++i) a[i] = read(); build(n);
	for (int i = 1; i <= n; ++i) ans1 ^= 1ll * i * tr[i][0] + i, ans2 ^= 1ll * i * tr[i][1] + i;	
	return printf("%lld %lld\n", ans1, ans2), 0;
}