#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f ^= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e6 + 5;

int m, n, tot;
int dat[N], deg[N], to[N];

queue<int> q;
vector<int> Num, e[N];

void rad(int x = 0, char ch = getchar(), bool isnum = false) {
	Num.clear(); int sign = 0;
	for (; ch != '\n' && ch != '\r' && ch != EOF; ch = getchar()) {
		if (isdigit(ch))
			isnum = true,
			x = (x << 1) + (x << 3) + (ch ^ 48);
		else {
			if (isnum) Num.push_back(x);
			x = isnum = 0; if(ch == '!') sign = 1;
		}
	}
	if (isnum) Num.push_back(x);
	if (Num.size() == 1) q.push(sign ? -Num[0] : Num[0]);
	else {
		deg[++ tot] = Num.size() - 1;
		for (auto v : Num) e[v].push_back(tot);
		to[tot] = sign? -Num[deg[tot]] : Num[deg[tot]]; 
	}
}

signed main() {
	m = read(), n = read();
	for (int i = 1; i <= m; ++i) rad();
	while(q.size()) {
		int x = q.front(); q.pop();
		if (x < 0) {
			x = -x;
			if (dat[x] > 0) return puts("conflict"), 0;
			dat[x] = -1;
		} else {
			if (dat[x] < 0) return puts("conflict"), 0;
			if (dat[x]) continue; dat[x] = 1;
			for (auto v : e[x]) {
				if (!(--deg[v])) q.push(to[v]);
			}
		}
	} for (int i = 1; i <= n; ++i) putchar(dat[i] == 1? 'T' : 'F');
	return 0;
}