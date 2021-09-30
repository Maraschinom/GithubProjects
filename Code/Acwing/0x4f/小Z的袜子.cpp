#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 5e4 + 5;

int n, m, siz, ans;
int col[N], bel[N], sum[N];

struct Feder_der_Katze{
	int l, r, id;
	int ans1, ans2;
	friend bool operator < (const Feder_der_Katze a, const Feder_der_Katze b) {
		if (bel[a.l] == bel[b.l]) return a.r < b.r;
		else return a.l < b.l; 
	}
}Katze[N];

bool compare(Feder_der_Katze a, Feder_der_Katze b) {
	return a.id < b.id;
}

int gcd(int x, int y) {return !y ? x : gcd(y, x % y);}

int sqr(int x) {return x * x;}

void revise(int x, int v) {ans -= sqr(sum[col[x]]), sum[col[x]] += v, ans += sqr(sum[col[x]]);}

signed main() {
	n = read(), m = read(), siz = sqrt(n);

	for (int i = 1; i <= n; ++i) col[i] = read(), bel[i] = i / siz + 1;

	for (int i = 1; i <= m; ++i) Katze[i].l = read(), Katze[i].r = read(), Katze[i].id = i;

	sort(Katze + 1, Katze + 1 + m); int l = 1, r = 0;
	for (int i = 1; i <= m; ++i) {

		while(l < Katze[i].l) revise(l, -1), ++l;
		while(l > Katze[i].l) revise(l - 1, 1), --l;
		while(r < Katze[i].r) revise(r + 1, 1), ++r;
		while(r > Katze[i].r) revise(r, -1), --r;

		if (Katze[i].l == Katze[i].r) {Katze[i].ans1 = 0, Katze[i].ans2 = 1; continue;}

		Katze[i].ans1 = ans - (Katze[i].r - Katze[i].l + 1);

		Katze[i].ans2 = (Katze[i].r - Katze[i].l + 1) * (Katze[i].r - Katze[i].l);

		int Gcd = gcd(Katze[i].ans1, Katze[i].ans2);
		Katze[i].ans1 /= Gcd, Katze[i].ans2 /= Gcd;

	} sort(Katze + 1, Katze + 1 + m, compare);
	for (int i = 1; i <= m; ++i) printf("%d/%d\n", Katze[i].ans1, Katze[i].ans2);
	return 0;
}