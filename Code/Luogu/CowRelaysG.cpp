#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int inf = 1e9 + 7, N = 1e6 + 5;

struct Matrix {
	int a[300][300], n, m;

	void insert(int rol, int col) {
		this -> n = rol, this -> m = col;
		for (int i = 1; i <= rol; ++i)
			for (int j = 1; j <= col; ++j) this -> a[i][j] = inf;
	}

	Matrix() {}
	Matrix(int R, int C) {insert(R, C);}

	friend Matrix operator * (Matrix a,  Matrix b) {
		Matrix result(a.n, b.m);
		for (int i = 1; i <= a.n; ++i)
			for (int j = 1; j <= b.m; ++j)
				for (int k = 1; k <= b.n; ++k)
					result.a[i][j] = min(result.a[i][j], a.a[i][k] + b.a[k][j]);
		return result;
	}

	Matrix qpow(Matrix x, int y) {
		Matrix result = x; -- y;	
		for (; y; y >>= 1, x = x * x) if (y & 1) result = result * x;
		return result;	
	}
}G;

int n, m, S, T, cnt, u, v, w;

int id[N];

signed main() {
	n = read(), m = read(), S = read(), T = read();
	G.insert(m << 1, m << 1);
	for (int i = 1; i <= m; ++i) {
		w = read(), u = read(), v = read();
		if (!id[u]) id[u] = ++ cnt;
		if (!id[v]) id[v] = ++ cnt;
		G.a[id[u]][id[v]] = min(G.a[id[u]][id[v]], w);
		G.a[id[v]][id[u]] = min(G.a[id[v]][id[u]], w);
	} G.n = cnt, G.m = cnt;
	G = G.qpow(G, n);
	return printf("%d\n", G.a[id[S]][id[T]]), 0;
}