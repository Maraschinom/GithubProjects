#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f ^= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 3e3 + 5;

#define lowbit(x) (x)&(-x)

int n;

struct Tree{int id, dep, siz, bot; int son[2];}tr[N];
bool compare(Tree x, Tree y) {return x.dep < y.dep;}

int fa[N];

void sol(int rt, int u, int d) {
	++ tr[rt].siz;
	if (tr[rt].dep > d) {
		if (!tr[rt].son[0]) {
			tr[rt].bot = tr[rt].son[0] = u;
			fa[tr[u].id] = tr[rt].id;
			return; 
		} int x;
		printf("? %d %d\n", tr[tr[rt].bot].id, tr[u].id);
		fflush(stdout); x = read();
		d = (tr[tr[rt].bot].dep + tr[u].dep - x) >> 1; // lca.dep
	}
	if (tr[rt].dep == d) {
		if (!tr[rt].son[0]) {
			tr[rt].son[0] = tr[rt].bot = u;
			fa[tr[u].id] = tr[rt].id;
			return;
		} else if (!tr[rt].son[1]) {
			tr[rt].son[1] = u;
			fa[tr[u].id] = tr[rt].id;
			return;
		} sol(tr[rt].son[1], u, d);
		if (tr[tr[rt].son[1]].siz > tr[tr[rt].son[0]].siz)
			swap(tr[rt].son[0], tr[rt].son[1]);
		tr[rt].bot = tr[tr[rt].son[0]].bot;
		return;
	}
	sol(tr[rt].son[0], u, d);
	tr[rt].bot = tr[tr[rt].son[0]].bot;
}

signed main() {
	n = read();
	for (int i = 1; i <= n; ++i) tr[i].id = i;
	for (int i = 2; i <= n; ++i) {
		printf("? %d %d\n", 1, i);
		fflush(stdout); tr[i].dep = read();
	} sort(tr + 2, tr + 1 + n, compare);
	for (int i = 1; i <= n; ++i) tr[i].siz = 1, tr[i].bot = i;
	for (int i = 2; i <= n; ++i) sol(1, i, -1);
	putchar('!');
	for (int i = 2; i <= n; ++i) printf(" %d", fa[i]);
	return puts(""), 0;
}