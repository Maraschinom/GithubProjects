#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
    for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    return f ? ~x + 1 : x;
}

const int N = 6e3 + 5;

int n, root, x, y;
int h[N];
int f[N][2];
vector<int> G[N];
bool vis[N];

void dfs(int x) {
    f[x][0] = 0, f[x][1] = h[x];
    for (auto v : G[x]) {
        dfs(v);
        f[x][0] += max(f[v][1], f[v][0]);
        f[x][1] += f[v][0];
    } return;
}

signed main() {
    n = read();
    for (int i = 1; i <= n; ++i) h[i] = read();
    for (int i = 1; i < n; ++i) {
        x = read(), y = read();
        vis[x] = true;
        G[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            root = i;
            break;
        }
    } dfs(root);
    return printf("%d\n", max(f[root][0], f[root][1])), 0;
}