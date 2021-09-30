#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 4e4 + 5;

int n, m, tot, siz, ans, l, r;
int num[N], recover[N], pos[N], t[N];
PII a[N]; vector<int> v[N];
int f[1005][1005];

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

void insert(int x) {
	int ans = 0, mx = 0;
	memset(t, 0, sizeof t);
	for (int i = (x - 1) * siz + 1; i <= n; ++i) {
		++ t[a[i].first];
		if (t[a[i].first] > mx) mx = t[a[i].first], ans = a[i].first;
		else if (t[a[i].first] == mx) ans = min(ans, a[i].first);
		f[x][pos[i]] = ans;
	}
}

int search(int l, int r, int x) {
	vector<int>::iterator a = upper_bound(v[x].begin(), v[x].end(), r);
	vector<int>::iterator b = lower_bound(v[x].begin(), v[x].end(), l);
	return a - b;
}

int ask(int l, int r) {
	int ans = f[pos[l] + 1][pos[r] - 1];
	int Saber = search(l, r, ans);
	for (int i = l; i <= min(r, pos[l] * siz); ++i) {

		int p = search(l, r, a[i].first);
		if (p > Saber) Saber = p, ans = a[i].first;
		else if (p == Saber) ans = min(ans, a[i].first);
	}
	if (pos[l] != pos[r])
		for (int i = (pos[r] - 1) * siz + 1; i <= r; ++i) {
			int p = search(l, r, a[i].first);
			if (p > Saber) Saber = p, ans = a[i].first;
			else if (p == Saber) ans = min(ans, a[i].first);
		}
	return ans;
}

bool cmp(PII x, PII y) {return x.second < y.second;}

signed main() {
	n = read(), m = read(); siz = (int)sqrt(n);
	for (int i = 1; i <= n; ++i) a[i] = {read(), i};
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (a[i].first != a[i - 1].first) ++ tot;
		recover[tot] = a[i].first;
		b[i] = tot;
	} for (int i = 1; i <= n; ++i) a[i].first = b[i]; 
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; ++i) v[a[i].first].push_back(i);
	for (int i = 1; i <= n; ++i) pos[i] = (i - 1) / siz + 1;
	for (int i = 1; i <= pos[n]; ++i) insert(i);
	while(m --) {
		l = read(), r = read();
		l = (l + ans - 1) % n + 1, r = (r + ans - 1) % n + 1;
		if (l > r) swap(l, r);
		printf("%d\n", ans = recover[ask(l, r)]);
	} return 0;
}