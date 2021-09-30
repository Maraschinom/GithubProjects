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

const int N = 1e5+5 ;
int n , m , v , opt[N] , l[N] , r[N] , sum ;
int a[N] ;
bool flag ; 

inline bool dfs(int x,int res) {
    if (x == n+1) return res == sum ;
    return dfs(x+1,res) | dfs(x+1,res+a[x]+1) ;
}

inline void solve(int x) {
    sum = 0 ;
    for (int i = l[x] ; i <= r[x] ; ++i ) sum += a[i] + 1 ;
    if (sum&1) return puts("No"),void() ;
    else { sum >>= 1 ; return puts(dfs(1,0)?"Yes":"No"),void() ; }
}

signed main() {
    fre(birthday) ;
    n = read() , m = read() , v = read() ;
    for (int i = 1 ; i <= n ; ++i ) a[i] = read() ;
    for (int i = 1 ; i <= m ; ++i ) {
        opt[i] = read() - 1 ;
        l[i] = read() ;
        r[i] = read() ;
        flag |= ( !opt[i] ) ;
    }
    if (!flag) return 0 ;
    else {
        for (int i = 1 ; i <= m ; ++i ) {
            if (r[i]-l[i] < 10)
                if (opt[i]) {
                    for (int j = l[i] ; j <= r[i] ; ++j ) a[j] = ( a[j] * a[j] % v ) * a[j] % v ;
                } else {
                    solve(i) ;
                }
            else if (!opt[i]) puts("Yes") ;
        }
    }
}