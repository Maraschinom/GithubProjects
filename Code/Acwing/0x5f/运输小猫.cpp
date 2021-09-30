#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar())  x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e5 + 5, M = 1e2 + 5;

int n, m, p, head, tail;

int q[N], d[N], a[N], s[N], t[N], h[N], f[M][N];

double getx(int i) {return i;}

double gety(int i, int j) {return f[i - 1][j] + s[j];}	

double sloup(int q, int i, int j) {
	return (gety(q, i) - gety(q, j) * 1.) / (getx(i) - getx(j));
}

signed main() {
	n = read(), m = read(), p = read();
	for (int i = 2; i <= n; ++i) d[i] = read() + d[i - 1];
	for (int i = 1; i <= m; ++i) {
		h[i] = read(), t[i] = read();
		a[i] = t[i] - d[h[i]];
	}

	sort(a + 1, a + 1 + m);

	for (int i = 1; i <= m; ++i) s[i] = s[i - 1] + a[i];

	memset(f, 0x3f, sizeof f);
	for (int i = 0; i <= p; ++i) f[i][0] = 0;

	for (int i = 1; i <= p; ++i) {
		head = tail = 0;                                                                                                                                                                                                                                                                                               
		for (int j = 1; j <= m; ++j) {
			while(head < tail && sloup(i, q[head], q[head + 1]) <= a[j]) ++ head;
			int k = q[head];
			f[i][j] = f[i - 1][k] - (s[j] - s[k]) + (j - k) * a[j];
			while(head < tail && sloup(i, q[tail], q[tail - 1]) >= sloup(i, j, q[tail])) -- tail;
			q[++ tail] = j;
		}
	} return printf("%lld\n", f[p][m]), 0;
}