#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 5e4 + 5;

int n, L, head, tail;
int s[N], g[N], f[N], q[N];

double getx(int u) {return g[u];}
double gety(int u) {return f[u] + (g[u] + L) * (g[u] + L);}
double sloup(int u, int v) {return (gety(u) - gety(v)) * 1. / (getx(u) - getx(v));}

signed main() {
	n = read(), L = read();
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + read();
	for (int i = 1; i <= n; ++i) g[i] = s[i] + i; q[tail] = 0;
	for (int i = 1; i <= n; ++i) {
		while(head < tail && sloup(q[head], q[head + 1]) < 2 * g[i]) ++ head;
		f[i] = f[q[head]] + (g[i] - g[q[head]] - L - 1) * (g[i] - g[q[head]] - L - 1);
		while(head < tail && sloup(q[tail], i) < sloup(q[tail], q[tail - 1])) -- tail;
		q[++ tail] = i;
	} return printf("%lld\n", f[n]), 0;