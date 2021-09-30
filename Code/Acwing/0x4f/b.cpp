#include <bits/stdc++.h>
using namespace std;
int T, n, a[201], b[201], ans[201];
int dp[201][201];
char s[201];
inline int mod(int x, int y) {
	return x > y ? mod(x - y, y) : x; 
}
inline bool dfs(int x, int l, int r) {
	if (l > r) return 1;
	if (dp[l][r] != -1)
        return dp[l][r];
	for (int mid = r - x; l <= mid; mid -= x)
		if (dfs(x, l, mid) && dfs(x, mid + 1, r))
			return dp[l][r] = 1;
	if (a[r] == b[mod(r - l + 1, x)])
		return dp[l][r] = dfs(x, l, r - 1);
	return dp[l][r] = 0;
}
inline bool check(int x) {
	for (int i = 1; i <= x; ++i)
		if (ans[i] > b[i])
			return false;
	return true;
}
int main() {
	cin >> s + 1;
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
		a[i] = s[i] - 'a' + 1;
	for (int i = 1; i <= n; ++i) {
		if (n % i) continue;
		int fl = 0;
		memset(ans, 0, sizeof ans);
		for (int j = 1; j < n - i; ++j) {
			memset(dp, -1, sizeof dp);
			for (int k = 1; k <= i; ++k)
				b[k] = a[j + k - 1];
			if (dfs(i, 1, n) && (!ans[1] || check(i)))
				for (int k = 1; k <= i; ++k)
					ans[k] = b[k];
		}
		if (ans[1]) {
			for (int k = 1; k <= i; ++k)
				printf("%c", (char)(ans[k] + 'a' - 1));
			puts(""); break;
		}
	}
	return 0;
}