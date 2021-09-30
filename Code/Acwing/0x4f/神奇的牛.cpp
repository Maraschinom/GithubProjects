#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? ~x + 1 : x; 
}

#define lowbit(x) (x)&(-x)

const int N = 1e5 + 5;

int n;
int s[N], a[N], h[N];

void add(int x,int y) {
	for (; x <= n; x += lowbit(x)) s[x] += y;
}

int ask(int x) {
	int ans = 0;
	for (; x; x -= lowbit(x)) ans += s[x];
	return ans;
}

int get(int x) {
	int l = 1, r = n;
	while(l < r) {
		int mid = l + r >> 1;
		if (ask(mid) < x) l = mid + 1;
		r = mid;
	} return l;
}

signed main() {
	n = read();
	for (int i = 2; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) add(i, 1);
	for (int i = n; i; --i) {
		h[i] = get(a[i] + 1);
		add(h[i], -1);
	}
	for (int i = 1; i <= n; ++i) printf("%d\n",h[i]);
}
