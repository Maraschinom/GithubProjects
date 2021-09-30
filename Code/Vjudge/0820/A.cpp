#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

const int N = 7e7 + 5;
const int M = 5e7;

int T, x, tot, ans;
int prime[N];
bool mark[N];
vector<int> pri, pri2;

signed main() {
	for (int i = 2; i <= M; ++i) {
		if (!prime[i]) {
			mark[i] = true, prime[i] = i, ++ tot;
			pri.push_back(i);
		}
		for (int j = 1; j <= tot; ++j) {
			if (pri[j - 1] > prime[i] || pri[j - 1] > M / i) break;
			prime[i * pri[j - 1]] = pri[j - 1];
		}
	}
	T = read();
	for (int i = 1; 2 * i + 1 <= M; ++i) if (mark[i + i + 1]) pri2.emplace_back(i + 1);
	while(T --) {
		x = read();
		if (x < 0) {
			x = ~x + 1;
			int p = *upper_bound(pri.begin(), pri.end(), x);
			int q = *upper_bound(pri2.begin(), pri2.end(), x + 1);
			ans = min(p << 1, (q << 1) - 1);
		} else {
			if (mark[x]) {printf("1\n"); continue;}
			if (mark[2 * x + 1] | mark[2 * x - 1]) {printf("2\n"); continue;}
			int p = *upper_bound(pri.begin(), pri.end(), x);
			int q = *upper_bound(pri2.begin(), pri2.end(), x + 1);
			ans = min(p << 1, (q << 1) - 1);
		} printf("%d\n", ans);
	} return 0;
}