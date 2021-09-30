#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 2e5 + 5e4 + 5;

int n, x0, y_0, p, r, siz, tot;
int L[N], R[N], D[N];
int x, y, m, pos, radio;
bool vis[N];

struct magnet{
	int x, y, m, p, r, dis;
	magnet() {x = y = m = p = r = 0;}
	magnet(int _x, int _y, int _m, int _p, int _r, int _d):x(_x), y(_y), m(_m), p(_p), r(_r), dis(_d) {}
	friend bool operator < (const magnet a, const magnet b) {
		return a.dis < b.dis;
	}
}a[N];

int sqr(int x) {return x * x;}

int calc(int x, int y) {return sqr(x - x0) + sqr(y - y_0);}

bool compare(magnet a, magnet b) {return a.m < b.m;}

signed main() {
	x0 = read(), y_0 = read(), a[0].p = read();
	a[0].r = read(), n = read(), siz = (int)sqrt(n);
	a[0].r = sqr(a[0].r);
	for (int i = 1; i <= n; ++i) {
		x = read(), y = read(), m = read();
		pos = read(), radio = read(); radio = sqr(radio);
		a[i] = magnet(x, y, m, pos, radio, calc(x, y));
	} sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i += siz) {
		L[++ tot] = i, R[tot] = min(n, i + siz - 1);
		D[tot] = a[R[tot]].dis;
		sort(a + L[tot], a + R[tot] + 1, compare);
	} int ans = 0; queue<magnet> Q;
	Q.push(a[0]); while(Q.size()) {
		magnet u = Q.front(); Q.pop();
		for (int i = 1; i <= tot; ++i) {
			if (D[i] > u.r) {
				for (int j = L[i]; j <= R[i]; ++j)
					if (!vis[j] && a[j].m <= u.p && a[j].dis <= u.r)
						vis[j] = true, Q.push(a[j]), ++ ans;
				break;
			} while(L[i] <= R[i] && a[L[i]].m <= u.p) {
				if (!vis[L[i]]) Q.push(a[L[i]]), ++ ans;
				++ L[i];
			}
		}
	} return printf("%lld\n", ans), 0;
}