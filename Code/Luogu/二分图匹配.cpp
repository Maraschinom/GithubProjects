#include <bits/stdc++.h>
using namespace std;
inline int read(register int x = 0 ,register bool f = 0 , register char ch = getchar()) {
    for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48); return f?~x+1:x;
}
const int N = 505 ;
int n , m , t , u , v , w , ans ;
int fa[N] , vistime[N] ;
vector<int> G[N<<1] ;
inline bool dfs(const int x,const int t) {
    if (vistime[x] == t) return false ;
    vistime[x] = t ;
    for (auto v : G[x]) {
        if (fa[v] && !dfs(fa[v],t)) continue ;
        fa[v] = x ;
        return true ;
    } return false ;
}
signed main() {
    n = read() , m = read() , t = read() ;
    for (register int i = 1 ; i <= t ; ++i ) u = read() , v =  read() , G[u].push_back(v) ;
    for (register int i = 1 ; i <= n ; ++i ) ans += dfs(i,i) ;   
    printf ("%lld\n",ans) ;
    fclose(stdin);fclose(stdout);return 0;
}