/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-10 17:54:33
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-10 19:20:50
*/

#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
    for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    return f ? ~x + 1 : x;
}

const int N = 5e3 + 5;

int n;
int a[N], s[N][N];
int f[N][N];

signed main() {
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read() + a[i - 1], f[i][i] = 0, s[i][i] = i;
    for (int i = 2; i <= n; ++i)
        for (int l = 1; l <= n - i + 1; ++l) {
            int r = l + i - 1; f[l][r] = 1e9 + 7;
            for (int k = s[l][r - 1]; k <= s[l + 1][r]; ++k) {
            	if (f[l][r] > f[l][k] + f[k + 1][r] + a[r] - a[l - 1]) {
            		f[l][r] = f[l][k] + f[k + 1][r] + a[r] - a[l - 1];
            		s[l][r] = k;
            	}
            }
        } return printf("%d\n", f[1][n]), 0;
}