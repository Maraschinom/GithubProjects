#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read(register int x = 0 ,register bool f = 0 , register char ch = getchar()) {
    for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48); return f?~x+1:x;
}
const int N = 2e5 + 5 ;
const int inf = 1e18 ;
int cnt , n , m , s , t , u , v , w ;
int h[1205] , d[1205] , prs[1205] , gap[1205] ;
struct Node {
    int v , w , nxt ;
} e[N<<1] ;

inline void add() {
    e[++cnt] = (Node){v,w,h[u]} ;
    h[u] = cnt ;
    e[++cnt] = (Node){u,0,h[v]} ;
    h[v] = cnt ;
}

struct cmp {
    int x , h ;
    cmp (int x=0,int h=0):x(x),h(h) {}
    inline bool operator < (const cmp &a) const {return h < a.h ;}
} ;

priority_queue<cmp> Q ;
inline bool push(int x,int y,int p) {
    int res = std::min(prs[x],e[p].w) ;
    e[p].w -= res ; e[p^1].w += res ; prs[x] -= res ; prs[y] += res ;
    return res ;
}

inline void Gap(int l,int s,int t) {
    for (int i = 1 ; i <= n ; ++i ) if (i != s && i != t && l < d[i] && d[i] <= n ) d[i] = n+1 ;
}

inline int maxflow(int s,int t) {
    while (!Q.empty()) Q.pop() ;
    memset(prs,0,sizeof prs) ; memset(d,0,sizeof d) ; memset(gap,0,sizeof gap) ;
    d[s] = n , prs[s] = inf , Q.push((cmp){s,d[s]}) ;
    while (!Q.empty()) {
        int x = Q.top().x ; Q.pop() ; if (!prs[x]) continue ;
        for (int i = h[x] , v = e[i].v ; i ; i = e[i].nxt , v = e[i].v) if ((x==s || d[x]==d[v]+1) && push(x,v,i) && v!=t && v!=s) Q.push(cmp(v,d[v]));
        if (x != s && x != t && prs[x]) {
            if (!(--gap[d[x]])) Gap(d[x],s,t) ;
            ++gap[++d[x]] ;
            Q.push(cmp(x,d[x])) ;
        }
    } return prs[t] ;
}

signed main() {
    n = read() , m = read() , s = read() , t = read() ;
    memset(h,0,sizeof h) ; cnt = 1 ;
    for (int i = 1 ; i <= m ; ++i ) u = read() , v = read() , w = read() , add() ;
    printf("%lld\n",maxflow(s,t)) ;
}