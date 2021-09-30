#include <iostream>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? ~x + 1 : x;
}

const int N = 1e5 + 5;

int n, m, idx, u, v, x;
int id[N], sum[N], lson[N], rson[N], f[N];
char opt[2];

void pushup(int rt) {
	return sum[rt] = sum[lson[rt]] + sum[rson[rt]];
}

int update(int rt, int l, int r, int x,int v) {
	if (!rt) rt = ++ idx;
	if (l == r) {
		id[rt] = v; ++ sum[rt];
		return rt;
	}
	int mid = l + r >> 1;
	if (x <= mid) lson[rt] = update(lson[rt], l, mid, x, v);
	else rson[rt] = update(rson[rt], mid + 1, r, x, v);
	pushup(rt); return rt;
}

int merge(int rt, int pre, int l, int r) {
	if (!rt) return pre;
	if (!pre) return rt;
	if (l == r) {
		if (id[pre]) {
			id[rt] = id[pre], sum[rt] += sum[pre];
			return rt;
		}
	} int mid = l + r >> 1;
	lson[rt] = merge(lson[rt], lson[pre], l, mid);
	rson[rt] = merge(rson[rt], rson[pre], mid + 1, r);
	pushup(rt); return rt;
}

int query(int rt, int k, int l, int r) {
	int ans = 0;
	if (sum[rt] < k || !rt) return 0;
	if (x == y) return id[rt];
	int mid = l + r >> 1;
	if (k <= sum[lson[rt]]) return query(lson[rt], k, l, mid);
	else query(rson[rt], k - sum[lson[rt]], mid + 1, r);
}

int find(int u){
	return f[u] == u? u : f[u] = find(u);
}

signed main(){
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) {
		x = read();
		f[i] = i;
		rt[i] = update(rt[i], 1, n, x, i);
	}
	for (int i = 1; i <= m; ++i) {
		u = find(read()), v = find(read());
		f[v] = u;
		rt[u] = merge(rt[u], rt[v], 1, n);
	}
	m = read();
	while(m --) {
		scanf("%s", opt + 1);
		u = find(read()), v = read();
		if (opt[0] == 'B') {
			v = find(v);
			if (u == v) continue;
			f[v] = u;
			rt[u] = merge(rt[u], rt[v], 1, n);
		} else {
			int ans = query
		}
	}
}
