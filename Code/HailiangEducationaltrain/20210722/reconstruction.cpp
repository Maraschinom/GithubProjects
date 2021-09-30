#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define int long long

namespace io {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using namespace io;

const int N = 55;
int n, C, cnt;
long long ans;
long long T[N], U[N], F[N], f[N];
long long value[N][N]; 
char Map[N][N];

struct Edge {
	int fr, to;
	long long val;
	friend bool operator < (Edge a, Edge b) {
		return a.val < b.val;
	}
}E[N * N];

long long Move_self(int x) {
	return 1LL * (U[x] + T[x] - 1) * (U[x] - T[x]) / 2 * F[x];
}

long long Move1(int x,int y) {
	return 1LL * (T[x] + T[y]) * C;
} 

int get(int x) {
	return x == f[x] ? x : f[x] = get(f[x]);
}

#define fre(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout);

signed main() {
	fre(reconstruction); n = read();
	for (int i = 1; i <= n; ++i) T[i] = read(), f[i] = i;
	for (int i = 1; i <= n; ++i) U[i] = read();
	for (int i = 1; i <= n; ++i) F[i] = read();
	for (int i = 1; i <= n; ++i) scanf("%s", Map[i] + 1);
	C = read();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if(i ^ j){
			int x = i, y = j; if (F[x] < F[y]) swap(x,y);
			value[i][j] = F[x] * T[y] * (U[x] - T[x]) + F[y] * U[x] * (U[y] - T[y]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		ans += Move_self(i);
		for (int j = i + 1; j <= n; ++j) if(Map[i][j] == 'Y') ans += value[i][j];  
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (Map[i][j] == 'Y') f[get(i)] = f[get(j)];
			else E[++cnt] = {i,j,value[i][j] + Move1(i,j)};
		}
	}
	sort(E + 1, E + 1 + cnt);
	for (int i = 1; i <= cnt; ++i) {
		int x = get(E[i].fr), y = get(E[i].to), z = E[i].val;
		if (x ^ y) ans += z, f[x] = y;
	}return printf("%lld\n", ans), 0;
}
