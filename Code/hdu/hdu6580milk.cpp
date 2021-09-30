/*
* @Author: Maraschino
* @Date:   2021-09-18 08:37:53
* @Last Modified by:   Maraschino
* @Last Modified time: 2021-09-18 10:41:04
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e4 + 5, inf = 0x3f3f3f3f3f3f3f3f;

class cow {

public:
	int x, y, t;
	friend bool operator < (const cow a, const cow b) {
		return a.y < b.y;
	}

	friend bool operator > (const cow a, const cow b) {
		return a.y > b.y;
	}

	cow() {}
	cow(int _x, int _y, int _t) {this -> x = _x, this -> y = _y, this -> t = _t;}

}milk[N];

int T, n, m, k;
int ans[N];

vector<int> solve(const vector<cow> &mp, int pos) { // If pos = -1, we will not have any limit in the position.
	vector<int> c(mp.size(), inf), t(mp.size(), inf); // If pos = mid, we'll move the person to the mid of the line in the end.
	c[0] = (pos == -1) ? 0 : abs(pos - mp[0].y), t[0] = 0;
	for (int i = 1; i < (int)mp.size(); ++i) {
		int dis = abs(mp[i].y - mp[i - 1].y); // in the same line
		for (int j = 0; j < i; ++j) t[j] += dis;
		for (int j = i; j; --j) t[j] = min(t[j], t[j - 1] + mp[i].t);
		for (int j = 0; j <= i; ++j) {
			int tmp = (pos == -1) ? 0 : abs(pos - mp[i].y);
			c[j] = min(c[j], tmp + t[j]);
		}
	} return c;
}

vector<int> merge(const vector<int> &a, const vector<int> &b) {
	vector<int> c(a.size() + b.size() - 1, inf);
	for (int i = 0; i < (int)a.size(); ++i)
		for (int j = 0; j < (int)b.size(); ++j)
			c[i + j] = min(c[i + j], a[i] + b[j]);
	return c; 
}

signed main() {
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	T = 1;
	while (T--) {
		n = read(), m = read(), k = read(); // Read an n * m matrix. 
		m = (m + 1) >> 1ll; // M is the mid of the line.
		
		vector<int> xaxis;
		xaxis.push_back(1ll);
		
		for (int i = 1; i <= k; ++i) 
			milk[i].x = read(), milk[i].y = read(), milk[i].t = read(), xaxis.push_back(milk[i].x);

		sort(xaxis.begin(), xaxis.end());
		xaxis.erase(unique(xaxis.begin(), xaxis.end()), xaxis.end()); //Get rid of duplicate numbers.
		
		vector<cow> a[N];

		for (int i = 1; i <= xaxis.size(); ++i) a[i].clear();
		for (int i = 1; i <= k; ++i) {
			int res = lower_bound(xaxis.begin(), xaxis.end(), milk[i].x) - xaxis.begin();
			a[res].push_back(milk[i]);
			ans[i] = inf;
		}

		for (int i = 0; i < (int)xaxis.size(); ++i) sort(a[i].begin(), a[i].end()); //Sort by row.

		vector<cow> T = a[0]; // Array T is the lines.
		vector<int> f[2]; // Array f is the result. f[0] means no position astrict and f[3] means the position is the mid of the line.

		T.insert(T.begin(), cow(1, 1, 0));

		f[0] = solve(T, m);
		vector<int> d = solve(T, -1);

		for (int i = 0; i < T.size(); ++i) ans[i] = min(ans[i], d[i]);

		for (int i = 1; i < (int)xaxis.size(); ++i) {
			vector<cow>::iterator it = lower_bound(a[i].begin(), a[i].end(), cow(i, m, 0));
			vector<cow> fr(a[i].begin(), it), bk(it, a[i].end()); // Fr is to left and bk is to right.
			fr.insert(fr.end(), cow(i, m, 0)); // Beacause we start at the mid of the line.
			bk.insert(bk.begin(), cow(i, m, 0));
			reverse(fr.begin(), fr.end()); // To left.


			vector<int> l, lb, r, rb;
			l = solve(fr, m), lb = solve(fr, -1);
			r = solve(bk, m), rb = solve(bk, -1);

			lb = merge(lb, r), rb = merge(rb, l);

			vector<int> g;
			g.resize(lb.size());

			for (int j = 0; j < (int)g.size(); ++j)
				g[j] = min(lb[j], rb[j]);
			g = merge(f[(i + 1) & 1], g);

			f[i & 1] = merge(f[(i + 1) & 1], merge(l, r));

			for (int j = 0; j < (int)g.size(); ++j) {
				ans[j] = min(ans[j], g[j] += xaxis[i] - xaxis[i - 1]); 
				f[i & 1][j] += xaxis[i] - xaxis[i - 1];
			}
		}

		for (int i = 1; i <= k; ++i) printf("%lld%c", ans[i], i == k ? '\n' : ' ');
	}
	return 0;
}