#include <bits/stdc++.h>
using namespace std;

inline int read(register int x=0,register char ch=getchar(),register bool f=0) {
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=true ;
    for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48) ;
    return f ? ~x+1 : x ;
}

#define FILE
#ifdef FILE
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#endif

const int Mod = 1e9+7 , N = 1e6+5 ;
int n , a , b , c , d , e , ans ;

inline void dfs(int len,int lst,int val) {
    if (len == n) { ans += val ; return ; }
    if (len > n) return ;
    if (lst == 1) {
        dfs(len+a,lst,val+d) ;
        dfs(len+b,2,val+e) ;
    } else {
        dfs(len+b,1,val+d) ;
        dfs(len+c,2,val+e) ;
    }
}

signed main() {
    fre(queue)
    n = read() ;
    a = read() , b = read() , c = read() , d = read() , e = read() ;
    dfs(0,1,d) ;
    dfs(0,2,e) ;
    printf("%d\n",ans) ;
    return 0 ;
}