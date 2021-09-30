#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;
typedef pair<int,int> PII ;

#define Make_Pair make_pair

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 2e5 + 5 ;
int it , mid , n , k , cnt , ans ;
int a[N] ;

signed main() {
    n = read() ; k = read() ;
    for (int i = 1 ; i <= n ; ++i )
        a[i] = read() ;
    sort(a + 1,a + 1 + n) ;
    it = (n - 1 >> 1) + 1 , mid = n + 1 >> 1 , ans = a[mid] ;
    while (k && it <= n) {
        if (k > (a[it] - ans) * cnt ) {
            k -= (a[it] - ans) * cnt ;
            ans += a[it] - ans , ++ cnt ;
            ++ it ;
        } else
            ans += k / cnt , k = 0 ;
    } if (k) {
        ans += k / cnt ;
        cnt = 0 ;
    } printf("%d\n",ans) ;
}