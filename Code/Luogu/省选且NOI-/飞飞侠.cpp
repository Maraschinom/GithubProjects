#include <bits/stdc++.h>

using namespace std;

#define int long long

template<typename T>
void read(T &x) {
    x = 0; int f = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    x = f ? ~x + 1 : x;
}

template<typename T, typename... Args>
void read(T &x, Args &...args) {
    read(x); read(args...);
}

const int N = 314;

const int dx[] = {0, 0, 0, 1, -1};
const int dy[] = {0, 1, -1, 0 ,0};
const char sub[] = {'X', 'Y', 'Z'};

int n, m, str;
int pre[3];
int a[N][N], b[N][N];
int f[N][N][N << 1];
bool vis[N][N][N << 1];

pair<int, int> loca[3];

const int inf = 1e15;

struct node {
    int x, y, Remstep, cost;

    node(): x(0), y(0), Remstep(0), cost(0) {}
    node(int _x, int _y, int _z, int w): x(_x), y(_y), Remstep(_z), cost(w) {}
    bool operator < (const node &antecedent) const {
        return cost > antecedent.cost;
    }
};

bool arrive(int id) {
    return vis[loca[id].first][loca[id].second][0];
}

void dijkstra(int id) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 0; k <= n + m; ++k)
                vis[i][j][k] = false, f[i][j][k] = inf;

    priority_queue<node> Q;
    int goalx = loca[id].first, goaly = loca[id].second;

    Q.push(node(goalx, goaly, b[goalx][goaly], a[goalx][goaly]));

    vis[goalx][goaly][0] = true; f[goalx][goaly][b[goalx][goaly]] = a[goalx][goaly];
    while (Q.size()) {
        if (arrive(0) && arrive(1) && arrive(2)) return;
        node u = Q.top(); Q.pop(); int k = u.Remstep;
    	if (vis[u.x][u.y][k]) continue;
    	vis[u.x][u.y][k] = true;
        if (k) {
            for (int i = 0; i < 5; ++i) {
                int xx = u.x + dx[i], yy = u.y + dy[i];
                if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
                if (f[xx][yy][k - 1] > f[u.x][u.y][k]) {
                    f[xx][yy][k - 1] = f[u.x][u.y][k];
                    Q.push(node(xx, yy, k - 1, f[xx][yy][k - 1]));
                }
            }
        } else if (f[u.x][u.y][b[u.x][u.y]] > f[u.x][u.y][0] + a[u.x][u.y]) {
            f[u.x][u.y][b[u.x][u.y]] = f[u.x][u.y][0] + a[u.x][u.y];
            Q.push(node(u.x, u.y, b[u.x][u.y], f[u.x][u.y][b[u.x][u.y]]));
        }
    }
}
signed main() {
//	#ifdef ONLINE_JUDGE
//    freopen("flyflyhero.in", "r", stdin);
//    freopen("flyflyhero.out", "w", stdout);
//	#endif
    read<int>(n, m);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            read<int>(b[i][j]), b[i][j] = min(b[i][j], 1ll * (max(i - 1, n - i) + max(j - 1, m - j)));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            read<int>(a[i][j]);
    for (int i = 0; i < 3; ++i)
        read<int>(loca[i].first, loca[i].second);

    for (int i = 0; i < 3; ++i) {
        dijkstra(i);
        for (int j = 0; j < 3; ++j) if (j != i)
    		pre[j] += f[loca[j].first][loca[j].second][0];
	}

    int ans = inf;
	ans = min(min(pre[0], min(pre[1], pre[2])), ans);
    for(int i = 2; ~i; --i) if (ans == pre[i]) str = sub[i];

	if (ans >= inf) return puts("NO"), 0;
	putchar(str); printf("\n%lld\n", ans);
    return 0;
}