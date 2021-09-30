#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;

inline int read(register int x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const int N = 5e5 + 5 ;
int n ;
int a[N] , b[N] ;
long long ans ;

void merge_sort(int l,int r) {
    if (r - l + 1 > 1) {
        int mid = (l + r) / 2 ;
        int idx = l ;
        merge_sort(l , mid) ;
        merge_sort(mid + 1 , r) ;
        int p = l , q = mid + 1 ;
        while (p <= mid || q <= r) {
            if (q > r || (p <= mid && a[p] <= a[q])) b[idx ++] = a[p ++] ;
            else b[idx ++] = a[q ++] , ans += mid - p + 1 ;
        }
        for (int i = l ; i <= r ; ++i ) a[i] = b[i] ; return ;
    }
}

signed main() {
    while(1) {
        n = read() ; if(!n) return 0 ; ans = 0 ;
        for (int i = 1 ; i <= n ; ++i ) a[i] = read() ;
        merge_sort(1,n) ; printf("%lld\n",ans) ;
    }
}