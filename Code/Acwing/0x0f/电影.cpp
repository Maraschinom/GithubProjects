#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;

inline int read(register int x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const int N = 2e5 + 5 ;
int n , m , ans , tot , idx = 1 /*, len */; 
int a[N] /*, p[3 * N]*/ ;
// int c[N] ;
pair<int,int> mv[N] ;
map<int,int> Value_Type ;

/*
inline int discrete() {
    int cnt = 0 ;
    for (int i = 1 ; i <= n + m + m ; ++i ) {
        if (i == 1 || p[i] != p[i-1])
            p[++cnt] = p[i] ;
    } return cnt ;
}
*/

signed main() {
    n = read() ;
    for (int i = 1 ; i <= n ; ++i ) /*p[i] = */ a[i] = read() ;
    m = read() ;
    for (int i = 1 ; i <= m ; ++i ) /*p[i + n] = */ mv[i].first = read() ; 
    for (int i = 1 ; i <= m ; ++i ) /*p[i + n + m] = */ mv[i].second = read() ;
    sort(a + 1 , a + 1 + n ) ;
    for (int i = 1 ; i <= n ; ++i ) ++Value_Type[a[i]] ;
    for (int i = 1 ; i <= m ; ++i ) {
        if (Value_Type[mv[i].first] > ans) 
            ans = Value_Type[mv[i].first] ;
    }
    for (int i = 1 ; i <= m ; ++i ) {
        if (Value_Type[mv[i].first] == ans)
            if (Value_Type[mv[i].second] > tot) tot = Value_Type[mv[i].second] , idx = i ;
    } return printf("%d\n",idx) , 0 ;
    /*
    sort(p + 1 , p + 1 + n + m + m) ; len = discrete() ;
    for (int i = 1 ; i <= n ; ++i ) a[i] = upper_bound(p + 1 , p + 1 + len , a[i] ) - p , ++ c[a[i]] ; //数据范围较大 需要离散化
    for (int i = 1 ; i <= m ; ++i ) mv[i].first = upper_bound(p + 1 , p + 1 + len , mv[i].first ) - p ;
    for (int i = 1 ; i <= m ; ++i ) mv[i].second = upper_bound(p + 1 , p + 1 + len , mv[i].second ) - p ;
    for (int i = 1 ; i <= m ; ++i ) {
        if (ans < c[mv[i].first])
            ans = c[mv[i].first] , idx = i ;
    }
    for (int i = 1 ; i <= m ; ++i ) { // 节省时间 /kk
        if (ans == c[mv[i].first]) 
            if (c[mv[i].second] > tot) tot = c[mv[i].second] , idx = i ;
    } printf("%d\n",idx) ; return 0 ;
    大数据wa了 求大佬指教
    */
}