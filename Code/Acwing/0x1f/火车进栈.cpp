#include <bits/stdc++.h>

using namespace std ;

inline int read(register int x = 0,register char ch = getchar(),register bool f = false) {
    for (;!isdigit(ch);ch = getchar()) f |= ch == '-' ; 
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 25 ;
int n , cnt , top , tot ;
int p[N] , st[N] ;

void dfs(int x) {
    if (x == n + 1) {
        if (++ cnt == 21) exit(0) ;
        for (int i = 1 ; i <= tot ; ++i ) printf("%d",p[i]) ;
        for (int i = top ; i ; --i ) printf("%d",st[i]) ; puts("") ;
        return ;
    } if (top) {
        p[++ tot] = st[top --] ;
        dfs(x) ;
        st[++ top] = p[tot --] ;
    }
    st[++ top] = x ;
    dfs(x + 1) ;
    -- top ;

}

signed main() {
    n = read() ;
    dfs(1) ;
} 