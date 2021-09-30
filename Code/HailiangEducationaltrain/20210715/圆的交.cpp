#pragma GCC optimize(3)
#pragma GCC optimize(1)
#pragma GCC optimize(fast)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

inline int read(register int x = 0, register bool f = false, register char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

typedef long long LL;
typedef pair<double, double> PDD;

class Circle {
public:
	PDD Circle_centre;
	double radius;
	friend bool operator < (const Circle &a, const Circle &b) {
		return a.radius < b.radius;
	}
};

class Segment {
public:
	double Down, Up;
	friend bool operator < (const Segment &x, const Segment &y) {
		if (x.Down == y.Down) return x.Up < y.Up;
		return x.Down < y.Down;
	}
};

const int N = 1e3 + 5;
const double eps = 1e-5;

int n, st, ed;

double ans;

Circle circle[N];

Segment s;

vector<Segment> S;

inline double sqr(register double x) {
	return x * x;
}

inline double f(register double x) {
	S.clear();
	for (register int i = st; i <= ed; ++i) {
		if (x < circle[i].Circle_centre.first - circle[i].radius) continue;
		if (x > circle[i].Circle_centre.first + circle[i].radius) continue;
		double len = x - circle[i].Circle_centre.first;
		len = sqrt(sqr(circle[i].radius) - sqr(len));
		s.Down = circle[i].Circle_centre.second - len, s.Up = circle[i].Circle_centre.second + len;
		S.push_back(s);
	}
	if (S.empty()) return 0.0;
	sort(S.begin(), S.end());
	double sum = 0.0, lst = S[0].Down;
	for (auto v : S) {
		if (v.Up > lst) {
			sum += v.Up - max(v.Down, lst);
			lst = v.Up;
		}
	} return sum;
}

inline double simpson(register double l, register double r) {
	double mid = (l + r) / 2; return (f(l) + 4 * f(mid) + f(r)) * (r - l) / 6;
}

inline double asr(register double l, register double r, register double eps, register double res) {
	double mid = (l + r) / 2, l2 = simpson(l, mid), r2 = simpson(mid, r);
	if (fabs(l2 + r2 - res) <= eps) return l2 + r2 + (l2 + r2 - res);
	return asr(l, mid, eps / 2, l2) + asr(mid, r, eps / 2, r2);
}

inline void solve() {
	register double l, r;
	register int i = 1, j;
	while (i <= n) {
		l = circle[i].Circle_centre.first - circle[i].radius,
			r = circle[i].Circle_centre.first + circle[i].radius;
		for (j = i + 1; j <= n; ++j) {
			if (circle[j].Circle_centre.first - circle[j].radius > r) break;
			r = max(circle[j].Circle_centre.first + circle[j].radius, r);
		}
		st = i, ed = j - 1, i = j;
		ans += asr(l, r, eps, simpson(l, r));
	} return;
}

inline double Euc_dis(PDD a, PDD b) {
	return sqrt(1.0 * sqr(a.first - b.first) + 1.0 * sqr(a.second - b.second));
}

inline void reset(register int tot = 0) {
	for (register int i = 1, j; i <= n; ++i) {
		for (j = i + 1; j <= n; ++j) {
			if (circle[i].radius - circle[j].radius + Euc_dis(circle[i].Circle_centre, circle[j].Circle_centre) < eps)
				break;
		}
		if (j > n) circle[++tot] = circle[i];
	} n = tot;
	return;
}

inline bool compare(Circle x, Circle y) {
	return x.Circle_centre.first + y.radius < y.Circle_centre.first + x.radius;
}

signed main() {
	n = read();
	for (register int i = 1; i <= n; ++i) {
		scanf("%lf", &circle[i].Circle_centre.first);
		scanf("%lf", &circle[i].Circle_centre.second);
		scanf("%lf", &circle[i].radius);
	}
	sort(circle + 1, circle + 1 + n); reset();
	sort(circle + 1, circle + 1 + n, compare); solve();
	return printf("%.3lf\n", ans), 0;
}