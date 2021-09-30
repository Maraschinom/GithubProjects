#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

int read(int x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;	
}

const int N = 1e6 + 5;
const int Digit = 30;

int n, k, T, tot, l, r, len;
int a[N], sum[N];
int val[N * Digit], Trie[N * Digit][2];

void insert(int x, int id) {
	int p = 0;
	for (int i = 30; ~i; --i) {
		int y = x >> i & 1;
		if (!Trie[p][y]) Trie[p][y] = ++tot;
		p = Trie[p][y];
	} val[p] = id;
}

int find(int x) {
	int p = 0;
	for (int i = 30; ~i; --i) {
		int y = x >> i & 1;
		if (Trie[p][!y]) p = Trie[p][!y];
		else p = Trie[p][y];
		if (!p) return -1;
	} return val[p];
}

signed main() {
	T = read();
	while(T--) {
		for (int i = 0; i <= tot; ++i)
			Trie[i][0] = Trie[i][1] = val[i] = 0;
		tot = 0, len = 0x3ffff; n = read(); k = read();
		for (int i = 1; i <= n; ++i) a[i] = read() ^ a[i - 1];
		for (int i = 1; i <= n; ++i) {
			int tmp = find(a[i]);
			if ((a[tmp] ^ a[i]) >= k)
				if (len > i - tmp + 1) 
					len = i - tmp + 1, l = tmp + 1, r = i;
			insert(a[i], i);
		}
		if (len == 0x3ffff) puts("-1");
		else printf("%d %d\n", l, r);
	} return 0;
}