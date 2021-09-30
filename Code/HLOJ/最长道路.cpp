#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> PII;

#define dis(i,j) (dep[i] + dep[j] - (dep[lca(i, j)] << 1))

int read(int x = 0, bool f = false, char ch = getchar()) {
    for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    return f? ~x + 1 : x;
}

const int N = 5e4 + 5;

int n, u, v, ans;
int son[N], Top[N], anc[N], siz[N], dep[N], Union[N];
PII val[N];
bool vis[N];
vector<int> G[N];

void dfs(int x) {
    siz[x] = 1;
    for (auto y : G[x]) if (y != anc[x])
        dep[y] = dep[x] + 1, anc[y] = x, dfs(y), siz[x] += siz[y],
        son[x] = siz[y] > siz[son[x]] ? y : son[x];
}

void dfs2(int x, int t) {
    Top[x] = t; if (son[x]) dfs2(son[x], t);
    for (auto y : G[x]) 
        if (y != anc[x] && y != son[x]) dfs2(y, y);
}

int lca(int x, int y) {
    while(Top[x] != Top[y]) {
        if (dep[Top[x]] > dep[Top[y]]) swap(x,y);
        y = anc[Top[y]];
    } return dep[x] < dep[y]? x : y;
}

int get(int x) {return Union[x] == x ? x : Union[x] = get(Union[x]);}

bool compare(PII a, PII b) {return a > b;}

struct Unicom{
    int x, y;
    Unicom(int _x, int _y): x(_x), y(_y) {}
    Unicom(): x(0), y(0) {}
}block[N];

void merge(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return;
    Union[x] = y;
    int a[4] = {block[x].x, block[x].y, block[y].x, block[y].y};
    if (dis(a[0], a[1]) > dis(block[y].x, block[y].y)) block[y] = Unicom(a[0], a[1]);
    if (dis(a[0], a[3]) > dis(block[y].x, block[y].y)) block[y] = Unicom(a[0], a[3]);
    if (dis(a[0], a[2]) > dis(block[y].x, block[y].y)) block[y] = Unicom(a[0], a[2]);
    if (dis(a[1], a[2]) > dis(block[y].x, block[y].y)) block[y] = Unicom(a[1], a[2]);
    if (dis(a[1], a[3]) > dis(block[y].x, block[y].y)) block[y] = Unicom(a[1], a[3]);
}

signed main() {
	freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
	n = read(); dep[1] = 1;
    for (int i = 1; i <= n; ++i) val[i] = make_pair(read(), i);
    sort(val + 1, val + 1 + n, greater<PII>());
    for (int i = 1; i < n; ++i)
        u = read(), v = read(),
        G[u].push_back(v), G[v].push_back(u);
    dfs(1), dfs2(1, 1);
    for (int i = 1; i <= n; ++i) Union[i] = block[i].x = block[i].y = i;
	for (int i = 1; i <= n; ++i) {
        for (auto v : G[val[i].second])
            if (vis[v]) merge(val[i].second, v);
		vis[val[i].second] = true; int u = get(val[i].second);
		ans = max(ans, val[i].first * (1LL + dis(block[u].x, block[u].y)));
	} printf("%lld\n", ans);
}
/*
3
5 3 5
1 2
1 3
*/
