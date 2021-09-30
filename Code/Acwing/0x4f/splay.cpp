#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>

using namespace std;

int read(int x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;	
}

const int N = 1e5 + 5;

int n, opt, x, root, tot;

struct node {
	int fa, siz, cnt, val;
	int son[2];
}tr[N];

void update(int x) {
	tr[x].siz = tr[tr[x].son[0]].siz + tr[tr[x].son[1]].siz + tr[x].cnt;
}

void rotate(int x) {
	int y = tr[x].fa, z = tr[y].fa;
	int k = tr[y].son[1] == x, w = tr[x].son[k ^ 1];
	tr[z].son[tr[z].son[1] == y] = x, tr[x].fa = z;
	tr[y].son[k] = w, tr[w].fa = y;
	tr[x].son[k ^ 1] = y, tr[y].fa = x;
	update(y), update(x);
}

void splay(int x, int goal) {
	while (tr[x].fa != goal) {
		int y = tr[x].fa, z = tr[y].fa;
		if (z != goal) 
			rotate((y == tr[z].son[0]) ^ (x == tr[y].son[0])? x : y);
		rotate(x);
	} if (!goal) root = x;
}

void insert(int x) {
	int u = root, f = 0;
	while (u && tr[u].val != x)
		f = u, u = tr[u].son[x > tr[u].val];
	if (u)
		++ tr[u].cnt;
	else {
		u = ++ tot;
		if (f) tr[f].son[x > tr[f].val] = u;
		tr[u].son[0] = tr[u].son[1] = 0, tr[u].fa = f;
		tr[u].val = x, tr[u].cnt = tr[u].siz = 1;
	} splay(u, 0);
}

void find(int x) {
	int u = root; if (!u) return;
	while(tr[u].son[x > tr[u].val] && x != tr[u].val)
		u = tr[u].son[x > tr[u].val];
	splay(u, 0);
}

int search(int x, int tmp) {
	find(x); int u = root;
	if (tr[u].val < x && !tmp) return u;
	if (tr[u].val > x && tmp) return u;
	u = tr[u].son[tmp];
	while(tr[u].son[tmp ^ 1]) u = tr[u].son[tmp ^ 1];
	return u;
}

void del(int x) {
	int pre = search(x, 0), suf = search(x, 1);
	splay(pre, 0); splay(suf, pre);
	int d = tr[suf].son[0];
	if (tr[d].cnt > 1)	
		-- tr[d].cnt, splay(d, 0);
	else
		tr[suf].son[0] = 0;
}

int rankk(int x) {
	find(x); return tr[tr[root].son[0]].siz;
}

int kvalue(int x) {
	int u = root; if (tr[u].siz < x) return 0;
	while(1) {
		int v = tr[u].son[0];
		if (x > tr[v].siz + tr[u].cnt)
			x -= tr[v].siz + tr[u].cnt,
			u = tr[u].son[1];
		else if (tr[v].siz >= x) u = v;
		else return tr[u].val;
	}
}

signed main() {
	n = read(); insert(1e9), insert(-1e9);
	for (int i = 1; i <= n; ++i) {
		opt = read(), x = read();
		switch(opt) {
			case 1: insert(x); break;
			case 2: del(x); break;
			case 3: printf("%d\n", rankk(x)); break;
			case 4: printf("%d\n", kvalue(x + 1)); break;
			case 5: printf("%d\n", tr[search(x, 0)].val); break;
			case 6: printf("%d\n", tr[search(x, 1)].val); break;
			default: break;
		}
	} return 0;
}
