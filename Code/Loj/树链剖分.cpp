/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-14 19:21:02
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-15 11:42:24
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int read(int x = 0, bool f = false, char ch = getchar()) {
    for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    return f ? ~x + 1 : x;
}

const int N = 2e5 + 5;

int n, tim, root, u, v, l, r, x, m, k, opt;
int a[N], b[N], dfn[N], siz[N], son[N], Top[N], anc[N], dep[N];
vector<int> G[N];

namespace Segment_Tree{
    struct ST{
        int w, add, l, r;
    }tr[N << 2];

    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    #define len(x) (tr[x].r - tr[x].l + 1)

    void pushdown(int rt) {
        tr[ls].w += len(ls) * tr[rt].add, tr[rs].w += len(rs) * tr[rt].add;
        tr[ls].add += tr[rt].add, tr[rs].add += tr[rt].add;
        tr[rt].add = 0;
    }

    void pushup(int rt) {tr[rt].w = tr[ls].w + tr[rs].w;}

    void build(int rt, int l, int r) {
        tr[rt].add = 0; tr[rt].l = l, tr[rt].r = r;
        if (l == r) {
            tr[rt].w = a[l];
            return;
        } int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        pushup(rt);
    }

    void update(int rt, int l, int r, int c) {
        if (l <= tr[rt].l && tr[rt].r <= r) {
            tr[rt].w += c * len(rt);
            tr[rt].add += c;
            return;
        } pushdown(rt);
        int mid = tr[rt].l + tr[rt].r >> 1;
        if (l <= mid) update(ls, l, r, c);
        if (r > mid) update(rs, l, r, c);
        pushup(rt);
    }

    int query(int rt, int l, int r) {
        if (l <= tr[rt].l && tr[rt].r <= r) {
            return tr[rt].w;
        } pushdown(rt);
        int mid = tr[rt].l + tr[rt].r >> 1, ans = 0;
        if (l <= mid) ans += query(ls, l, r);
        if (r > mid) ans += query(rs, l, r);
        return ans;
    }
};


namespace prepare{
    void dfs(int x) {
        siz[x] = 1, dep[x] = dep[anc[x]] + 1;
        for (auto v : G[x]) {
            if (v == anc[x]) continue;
            anc[v] = x; dfs(v); siz[x] += siz[v];
            if (!son[x] || siz[v] > siz[son[x]]) son[x] = v;
        } return;
    }

    void dfs2(int x, int top) {
        dfn[x] = ++ tim; Top[x] = top; a[tim] = b[x];
        if (son[x]) dfs2(son[x], top);
        for (auto v : G[x]) {
            if (v == anc[x] || v == son[x]) continue;
            dfs2(v, v);
        } return;
    }

    int lca(int x, int y) {
        while (Top[x] != Top[y]) {
            if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
            x = anc[Top[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        return x;
    }

    int find(int x, int y) {
        while(Top[x] != Top[y]) {
            if (anc[Top[y]] == x) return Top[y];    
            y = anc[Top[y]];
        } return son[x];
    }
};

namespace solve{
    void addchain(int x, int y, int val) {
        while (Top[x] != Top[y]) {
            if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
            Segment_Tree::update(1, dfn[Top[x]], dfn[x], val);
            x = anc[Top[x]];
        } if (dep[x] > dep[y]) swap(x, y);
        Segment_Tree::update(1, dfn[x], dfn[y], val);
    }

    void addsub(int x, int val) {
        if (prepare::lca(x, root) != x) // Root has no effect on X because that root is the ancestors of X
            Segment_Tree::update(1, dfn[x], dfn[x] + siz[x] - 1, val);
        else if (root == x) // X is the root and all of the node is X's son.
            Segment_Tree::update(1, 1, n, val);
        else {
            int p = prepare::find(x, root); // All node in X's subtree except this subtree's node.
            Segment_Tree::update(1, 1, dfn[p] - 1, val); // So we find this subtree to reduce themselves.
            if (dfn[p] + siz[p] <= n)
                Segment_Tree::update(1, dfn[p] + siz[p], n, val); // Add all the node and reduce this subtree's node.
        }
    }

    int askchain(int x, int y) {
        int ans = 0;
        while (Top[x] != Top[y]) {
            if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
            ans += Segment_Tree::query(1, dfn[Top[x]], dfn[x]);
            x = anc[Top[x]];
        } if (dep[x] > dep[y]) swap(x, y);
        ans += Segment_Tree::query(1, dfn[x], dfn[y]);
        return ans;
    }

    int asksub(int x) {
        if (prepare::lca(x, root) != x) return Segment_Tree::query(1, dfn[x], dfn[x] + siz[x] - 1);
        else if (root == x) return Segment_Tree::query(1, 1, n);  
        int ans = 0, p = prepare::find(x, root);
        ans += Segment_Tree::query(1, 1, dfn[p] - 1);
        if (dfn[p] + siz[p] <= n)
            ans += Segment_Tree::query(1, dfn[p] + siz[p], n);
        return ans;
    }
};

signed main() {
    n = read();
    for (int i = 1; i <= n; ++i) b[i] = read();
    for (int i = 2; i <= n; ++i) {
        x = read(); G[x].push_back(i);
        G[i].push_back(x);
    } prepare::dfs(1); prepare::dfs2(1, 1);
    m = read(); Segment_Tree::build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        opt = read();
        if (opt == 1) root = read();
        if (opt == 2) u = read(), v = read(), k = read(), solve::addchain(u, v, k);
        if (opt == 3) u = read(), k = read(), solve::addsub(u, k);
        if (opt == 4) u = read(), v = read(), printf("%lld\n", solve::askchain(u, v));
        if (opt == 5) u = read(), printf("%lld\n", solve::asksub(u));
    } return 0;
}