#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n;
int s[N], ans[N];

void add(int x, int v) {
	for (; x <= n; x += lowbit(x)) s[x] = max(s[x], v);
}

int ask(int x) {
	int ans = 0;
	for (; x; x -= lowbit(x)) ans = max(ans, s[x]);
	return ans;
}

void del(int x) {
	for (; x; x -= lowbit(x)) s[x] = 0;
}

void cdq(int l, int r) {
	if (l == r) return;
	int mid = l + r >> 1;
	cdq(l, mid), cdq(mid + 1, r);
	
}

int main() {

	return 0;	
}