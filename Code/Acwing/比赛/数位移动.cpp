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
int T , n , idx ;
int arr[N] , ans[N] , f[N] , bel[N] ;
bool vis[N] ;
int son[N] ;
queue<PII> Q ;

void find(int x) {
    vis[x] = true ; bel[x] = idx ;
    if (vis[son[x]]) return ;
    else {
        ++ ans[idx] ;
        find(son[x]) ;
    } return ;
}

signed main() {
    T = read() ;
    while (T --) {
        n = read() ; idx = 0 ;
        for (int i = 1 ; i <= n ; ++i ) f[i] = read() , son[i] = f[i] ;
        for (int i = 1 ; i <= n ; ++i ) if (!vis[i]) ++ idx , find(i) ;
        for (int i = 1 ; i <= n ; ++i ) printf("%d%c",ans[bel[i]] + 1,i == n ? '\n' : ' ') ;
        for (int i = 1 ; i <= idx ; ++i ) ans[i] = 0 ;
        for (int i = 1 ; i <= n ; ++i ) vis[i] = false ;
    } return 0 ;
}