#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

namespace Read {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using Read::read;

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

const int N = 3e6 + 5;

int n, ans;
int l[N], lst[30], s[N];
int f[N][30];
int d[N], a[N];
char str[N], substr[N];
vector<pair<int, int> > vec;

int query(int l, int r) {
	int k = log(r - l + 1) / log(2);
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

signed main() {
	fre(string);
	n = read();
	scanf("%s", str + 1);
	scanf("%s", substr + 1);
	for (int i = 1; i <= n; ++i) {
		lst[str[i] - 'a'] = i;
		l[i] = lst[substr[i] - 'a'];
	}
	for (int i = 1; i <= n; ++i) {
		if (!l[i]) return puts("-1"), 0;
	}
	for (int i = n; i; --i) {
		if (i != n && substr[i] == substr[i + 1]) continue;
		if (substr[i] == str[i]) continue;
		vec.push_back(make_pair(l[i] + 1, i));
		d[l[i] + 1] += 1;
		d[i + 1] -= 1;
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = a[i - 1] + d[i];
	}
	for (int i = 1; i <= n; ++i) f[i][0] = a[i];
	int t = log(n) / log(2) + 1;
	for (int j = 1; j < t; ++j)
		for (int i = 1; i <= n - (1 << j) + 1; ++i)
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
	sort(vec.begin(), vec.end());
	for (int i = 0; i < (int)vec.size(); ++i) {
		int L = vec[i].first;
		int R = vec[i].second;
		while (i != (int)vec.size() - 1 && vec[i + 1].first <= vec[i].second) {
			++i;
			R = max(R, vec[i].second);
		}
		ans += query(L, R);
	} return printf("%d\n", ans), 0;
}
