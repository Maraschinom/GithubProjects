#include <bits/stdc++.h>
using namespace std;
#define N 10005
#define LL long long
#define MP make_pair
LL T, n, m, k, f[N], ans[N];
LL l[N], l_back[N], r[N], r_back[N], g[N];
LL g_back[N], nxt[N];
pair<LL, LL>cost[N];
map<LL, vector<pair<LL, LL>>>mp;
void init() {
    mp.clear();
    scanf("%lld%lld%lld", &n, &m, &k);

    for (int i = 1; i <= k; i++)
        f[i] = ans[i] = 1e18;

    for (int i = 1; i <= k; i++) {
        LL R, c, t;
        scanf("%lld%lld%lld", &R, &c, &t);
        mp[R].push_back(MP(c, t));
    }

    f[0] = ans[0] = m - 1 >> 1;
    LL lst = 1, mx = 0;

    for (const auto &pi : mp) {
        LL R = pi.first;
        auto d = pi.second;
        d.push_back(MP(0, 0));
        sort(d.begin(), d.end());
        LL n = d.size() - 1, cnt = 0, mid = m + 1 >> 1;

        for (int i = 1; i <= n; i++)
            if (d[i].first < mid)
                cnt++;

        d[0].first = mid;

        if (R == 1) { //对当前行为1的特判
            nxt[0] = 1;

            for (int i = 1; i <= n; i++)
                nxt[i] = i + 1, r[i] = r_back[i] = 1e18;

            for (int i = 1; i <= n; i++)
                cost[i] = MP(d[i].second, i);

            sort(cost + 1, cost + n + 1);

            for (int i = n; i >= 1; i--) {
                LL sum = 0, id = 0;

                for (int j = nxt[0], k = 1; j <= n; j = nxt[j], k++) {
                    sum += cost[j].first;
                    r[k] = min(r[k], sum + d[i].first - 1);

                    if (nxt[j] <= n && cost[nxt[j]].second == i)
                        id = j;

                    r_back[k] = min(r_back[k], sum + 2 * max(d[i].first, mid) - mid - 1);
                }

                nxt[id] = nxt[nxt[id]];
            }

            for (int i = 1; i <= n; i++) {
                ans[i] = min(ans[i], r[i]);
                f[i] = min(f[i], r_back[i]);
            }

            mx = n;
            continue;
        }

        nxt[0] = 1;

        for (int i = 1; i <= cnt; i++) {
            cost[i] = MP(d[i].second, i);
            l[i] = l_back[i] = 1e18;
            nxt[i] = i + 1;
        }

        sort(cost + 1, cost + cnt + 1); //对喝水耗时进行排序

        for (int i = 1; i <= cnt; i++) { //枚举最远走到哪，从远到近枚举
            LL sum = 0, id = 0;

            for (int j = nxt[0], k = 1; j <= cnt; j = nxt[j], k++) { //取前k小的喝水耗时，更新答案
                sum += cost[j].first;
                l[k] = min(l[k], sum + mid - d[i].first);

                if (nxt[j] <= cnt && cost[nxt[j]].second == i)
                    id = j;

                l_back[k] = min(l_back[k], sum + 2 * (mid - d[i].first));
            }

            nxt[id] = nxt[nxt[id]]; //删除当前最远点
        }

        nxt[cnt] = cnt + 1;

        for (int i = cnt + 1; i <= n; i++) {
            cost[i] = MP(d[i].second, i);
            r[i - cnt] = r_back[i - cnt] = 1e18;
            nxt[i] = i + 1;
        }

        sort(cost + cnt + 1, cost + n + 1);

        for (int i = n; i > cnt; i--) {
            LL sum = 0, id = cnt;

            for (int j = nxt[cnt], k = 1; j <= n; j = nxt[j], k++) {
                sum += cost[j].first;
                r[k] = min(r[k], sum + d[i].first - mid);

                if (nxt[j] <= n && cost[nxt[j]].second == i)
                    id = j;

                r_back[k] = min(r_back[k], sum + 2 * (d[i].first - mid));
            }

            nxt[id] = nxt[nxt[id]];
        }

        for (int i = 1; i <= n; i++) { //合并l, r
            g[i] = g_back[i] = 1e18;

            for (int j = max(0ll, i - (n - cnt)); j <= min(1ll * i, cnt); j++) {
                g[i] = min(g[i], min(l[j] + r_back[i - j], l_back[j] + r[i - j]));
                g_back[i] = min(g_back[i], min(l_back[j] + r_back[i - j], l_back[j] + r_back[i - j]));
            }
        }

        for (int i = 0; i <= mx; i++) { //更新ans
            f[i] += R - lst; //先加上走过的行数

            for (int j = 1; j <= n; j++)
                ans[i + j] = min(ans[i + j], f[i] + g[j]);
        }

        for (int i = mx; i >= 0; i--) //更新f
            for (int j = n; j >= 1; j--)
                f[i + j] = min(f[i + j], f[i] + g_back[j]);

        mx += n, lst = R; //更新上一次走到的行数
    }

    for (int i = 1; i <= k; i++)
        printf("%lld%c", ans[i], i < k ? ' ' : '\n');
}
int main() {
    scanf("%lld", &T);

    while (T--)
        init();
}