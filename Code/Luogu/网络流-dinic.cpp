#pragma GCC diagnostic error "-std=c++11" 
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
inline int read(register int x = 0 ,register bool f = 0 , register char ch = getchar()) {
    for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48); return f?~x+1:x;
}
struct Node{
    int v,w,Index;
};
const int N = 1e4+5 ;
int n , m , s , t , ans , cnt = 1 , u , v , w ;
int dep[N] , val[N] ;
vector<Node>G[N];
queue<int> q;
inline bool bfs() {
    memset(dep,0,sizeof dep) ;
    while(q.size()) q.pop() ;
    q.push(s) ;
    dep[s] = 1 ;
    while (q.size()) {
        int u = q.front() ; q.pop() ;
        for (auto v:G[u]) if (val[v.Index]&&!dep[v.v]) dep[v.v] = dep[u] + 1 , q.push(v.v) ;
    } return dep[t] ;
}
inline int dfs(int u,int inflow) {
    if (u == t) return inflow ;
    int out = 0 ;
    for(auto v:G[u]) {
        if (!inflow) break ;
        if (val[v.Index] && dep[v.v] == dep[u] + 1 ) { int res = dfs(v.v,std::min(val[v.Index],inflow)) ; val[v.Index] -= res , val[v.Index^1] += res , inflow -= res , out += res ; }
    } 
    if (out == 0) dep[u] = 0 ;
    return out ;
}
signed main() {
    n = read() ; m = read() ; s = read() ; t = read() ;
    for (register int i = 1 ; i <= m ; ++i ) u = read() , v = read() , w = read() , G[u].push_back((Node){v,w,++cnt}) , G[v].push_back((Node){u,0,++cnt}) , val[cnt] = 0 , val[cnt-1] = w ;
    while (bfs()) ans += dfs(s,1e18) ; printf("%lld\n",ans) ;
}