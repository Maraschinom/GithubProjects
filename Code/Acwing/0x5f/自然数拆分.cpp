#include <bits/stdc++.h>

#define int long long

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
    for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    return f ? ~x + 1 : x;
}

const int N = 1e4 + 5, mod = 2147483648;

int n;
int f[N];

signed main() {
    n = read(); f[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            (f[j] += f[j - i]) %= mod;
    return printf("%lld\n", (f[n] - 1 + mod) % mod), 0;
}