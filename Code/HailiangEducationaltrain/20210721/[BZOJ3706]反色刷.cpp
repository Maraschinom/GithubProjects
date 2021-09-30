#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(fast)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

char buf[1 << 20], *p1, *p2;
#define getchar() ((p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)

inline int read(int x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 1e6 + 5;
int n, m, cnt, ans, q;
int u[N], v[N], w[N], fa[N], sum[N], deg[N];

int get(int x) {
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}

signed main() {
	n = read(), m = read();
	for (register int i = 1; i <= n; ++i) fa[i] = i;
	for (register int i = 1; i <= m; ++i) {
		u[i] = read(), v[i] = read(), w[i] = read();
		int f = get(u[i]), ff = get(v[i]);
		if (f != ff) {
			if (sum[f] && sum[ff]) --ans;
			sum[f] += sum[ff]; fa[ff] = f;
		}
		if (w[i]){
			if (++sum[f] == 1) ++ans;
			++deg[u[i]], ++deg[v[i]];
			if (deg[u[i]] & 1) ++cnt;
			else --cnt;
			if (deg[v[i]] & 1) ++cnt;
			else --cnt;
		}
	} q = read();
	for (register int i = 1; i <= q; ++i) {
		int opt = read();
		if (opt & 1) {
			register int id = read() + 1;
			w[id] ^= 1;
			int f = get(u[id]);
			if (w[id]) {
				if (++sum[f] == 1) ++ans;
				++deg[u[id]], ++deg[v[id]];
				if (deg[u[id]] & 1) ++cnt;
				else --cnt;
				if (deg[v[id]] & 1) ++cnt;
				else --cnt;
			}
			else {
				if (!(--sum[f])) --ans;
				--deg[u[id]], --deg[v[id]];
				if (deg[u[id]] & 1) ++cnt;
				else --cnt;
				if (deg[v[id]] & 1) ++cnt;
				else --cnt;
			}
		} else {
			if (cnt) puts("-1");
			else printf("%d\n",ans);
		}
	} return 0;
}