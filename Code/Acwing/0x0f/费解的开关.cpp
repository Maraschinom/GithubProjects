#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std ;

inline int read(register int x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x+1 : x ;
}

const int N = 105 , inf = 1e9+7 ;
int n , ans , step ;
const int dx[] = {1,-1,0,0,0} ;
const int dy[] = {0,0,1,-1,0} ;
int a[5][5] ;
int op[5][5] ;
int f[5][5] ;
char cc[5] ;

void turn(int x,int y) {
    for (int i = 0 ; i < 5 ; ++i ) {
        int xx = x + dx[i] , yy = y + dy[i] ;
        if (xx == -1 || xx == 5 || yy == -1 || yy == 5) continue ;
        f[xx][yy] = !f[xx][yy] ;
    }
}

void solve() {
    bool flag = false ;
    for (int i = 0 ; i < 4 ; ++i )
        for (int j = 0 ; j < 5 ; ++j ) {
            if (!f[i][j]) {
                ++ step ;
                turn(i + 1,j) ;
            }
        }
    for (int i = 0 ; i < 5 ; ++i )
        if (!f[4][i]) flag = true ;
    if (!flag)
        ans = std::min(ans,step) ;
}

void pre() {
    for (int i = 0 ; i < 1 << 5 ; ++i ) {
        memcpy(f,a,sizeof a) ;
        step = 0 ;
        for (int j = 0 ; j < 5 ; ++j )
            if (((i >> j) & 1)) {
                ++ step ;
                turn(0,j) ;
            }
        solve() ;
    }
}

signed main() {
    n = read() ;
    while (n --) {
        ans = inf ;
        for (int i = 0 ; i < 5 ; ++i ) {
            scanf("%s",cc) ;
            for (int j = 0 ; j < 5 ; ++j )
                a[i][j] = cc[j] == '1' ;
        }
        pre() ;
//      cout << ans << endl ;
        printf("%d\n",ans > 6 ? -1 : ans ) ;
    }
    return 0 ;
}