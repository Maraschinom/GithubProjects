#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
    for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    return f ? ~x + 1 : x;
}

const int N = 5e5 + 5;

int n, m, k, x, y;
int a[N];

namespace Segment_Tree{
    
    struct Segment_Tree{
        int sum, lmax, rmax, dat;
        int l, r;
        Segment_Tree(): sum(0), lmax(0), rmax(0), dat(0), l(0), r(0) {}
        Segment_Tree(int x, int _l, int _r): sum(x), lmax(x), rmax(x), dat(x), l(_l), r(_r) {}
    }tr[N << 2];

    #define ls (rt << 1)
    #define rs (rt << 1 | 1)

    void pushup(int rt) {
        tr[rt].sum = tr[ls].sum + tr[rs].sum;
        tr[rt].lmax = max(tr[ls].lmax, tr[ls].sum + tr[rs].lmax);
        tr[rt].rmax = max(tr[rs].rmax, tr[rs].sum + tr[ls].rmax);
        tr[rt].dat = max(max(tr[ls].dat, tr[rs].dat), tr[ls].rmax + tr[rs].lmax); 
    }

    void build(int rt, int l, int r) {
        tr[rt].l = l, tr[rt].r = r;
        if (l == r) {
            tr[rt].sum = tr[rt].dat = tr[rt].lmax = tr[rt].rmax = a[l];
            return;
        } int mid = l + r >> 1;
        build(ls, l, mid), build(rs, mid + 1, r), pushup(rt);
    }

    void update(int rt, int x, int w) {
        if (tr[rt].l == tr[rt].r) {
            tr[rt] = Segment_Tree(w, tr[rt].l, tr[rt].r);
            return;
        } int mid = tr[rt].l + tr[rt].r >> 1;
        if (mid >= x) update(ls, x, w);
        else update(rs, x, w); pushup(rt);
    }

    Segment_Tree query(int rt, int l, int r) {
        if (l <= tr[rt].l && tr[rt].r <= r)
            return tr[rt];
        int mid = tr[rt].l + tr[rt].r >> 1;
        Segment_Tree a(-0x3ffff, 0, 0), b(-0x3ffff, 0, 0), c;
        if (l <= mid)
            a = query(ls, l, r), c.sum += a.sum;
        if (r > mid)
            b = query(rs, l, r), c.sum += b.sum;
        c.dat = max(max(a.dat, b.dat), a.rmax + b.lmax);
        c.lmax = max(a.lmax, a.sum + b.lmax);
        c.rmax = max(b.rmax, b.sum + a.rmax);
        return c;
    }
}

using namespace Segment_Tree;

signed main() {
    n = read(), m = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        k = read(), x = read(), y = read();
        if (k == 1) printf("%d\n", query(1, x > y ? y : x, x > y ? x : y).dat);
        else update(1, x, y);
    } return 0;
}