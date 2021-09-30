/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-11 14:39:26
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-11 19:07:18
*/

#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e5 + 5;
const double eps = 1e-9;

int n, top;
int st[N];

struct cash{
	double a, b, rate, x, y, id, f;
}c[N];

bool cmp(cash a, cash b) {return a.y * a.f < b.y * b.f;}

bool rebuild(cash a, cash b) {return a.id < b.id;}

double X(int id) {return c[id].y * c[id].f;}
double Y(int id) {return c[id].x * c[id].f;}
double slope(int id) {return -c[id].b / c[id].a;}

double slope(int id1, int id2) {
	if(fabs(X(id1) - X(id2)) < eps) return 1e9;
	return (Y(id1) - Y(id2)) / (X(id1) - X(id2));
}

void divid(int l, int r) {
	if (l == r) {c[l].f = max(c[l].f, c[l - 1].f); return;}
	int mid = l + r >> 1; divid(l, mid);
	sort(c + l, c + mid + 1, cmp); top = 0;
	for (int i = l; i <= mid; ++i) {
		while(top > 1 && slope(st[top - 1], st[top]) <= slope(st[top], i)) -- top;
		st[++ top] = i;
	}
	for (int i = mid + 1; i <= r; ++i) {
		int pos = 1;
		for (int j = 1 << 20; j; j /= 2)
			if (pos + j <= top && slope(st[pos + j - 1], st[pos + j]) >= slope(i))
				pos += j;
		c[i].f = max(c[i].f, c[i].a * (Y(st[pos]) - slope(i) * X(st[pos])));
	} sort(c + l, c + r + 1, rebuild);
	divid(mid + 1, r);
}

signed main() {
	n = read(); scanf("%lf", &c[0].f);
	
	for (int i = 1; i <= n; ++i)
		scanf("%lf%lf%lf", &c[i].a, &c[i].b, &c[i].rate);

	for (int i = 1; i <= n; ++i) {
		c[i].id = i;
		c[i].x = c[i].rate / (c[i].a * c[i].rate + c[i].b);
		c[i].y = 1. / (c[i].a * c[i].rate + c[i].b);
	} divid(1, n);
	return printf("%.3lf\n", c[n].f), 0;
}