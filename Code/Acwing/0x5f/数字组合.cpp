#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
    for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    return f ? ~x + 1 : x;
}

const int N = 1e2 + 5, M = 1e4 + 5;

int n, m;
int a[N], f[M];

int main(int argc, char *argv[]) {
    n = read(), m = read(); f[0] = 1;
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= a[i]; --j)
            f[j] += f[j - a[i]];
    return printf("%d", f[m]), 0;
}