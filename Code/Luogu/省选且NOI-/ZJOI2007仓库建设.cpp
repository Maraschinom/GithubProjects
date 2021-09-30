/*
* @Author: Maraschino
* @Date:   2021-09-23 14:20:06
* @Last Modified by:   Maraschino
* @Last Modified time: 2021-09-29 13:45:50
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e6 + 5;
const double eps = 1e-9;

int n, head, tail;
int f[N], sum[N], def[N];
int a[N], c[N], p[N], q[N];

double y(int id) {return f[id] + def[id];}
double x(int id) {return sum[id];}
double slope(int u, int v) {return (y(u) - y(v)) / (x(u) - x(v));}

signed main() {
	n = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read(), p[i] = read(), c[i] = read();
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + p[i], def[i] = def[i - 1] + 1ll * a[i] * p[i];
	head = tail = 0;
	for (int i = 1; i <= n; ++i) {
		while (head < tail && slope(q[head], q[head + 1]) + eps <= a[i]) ++ head;
		int p = q[head];
		f[i] = f[p] + 1ll * a[i] * (sum[i] - sum[p]) - (def[i] - def[p]) + c[i];
		while (head < tail && slope(q[tail], q[tail - 1]) - eps >= slope(q[tail], i)) -- tail;
		q[++ tail] = i;
	} int ans = f[n];
    for (int i = n; i; --i) {
    	ans = min(f[i], ans);
    	if (p[i]) break;
    } return printf("%lld\n", ans), 0;
}fuck u ccf.