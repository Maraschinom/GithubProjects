#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std ;

typedef pair<int,int> PII ; 
#define MK make_pair
#define fre(x) \
freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

class state {
    public :
        int weight , value , cost ;
} ;

const int N = 3e3 + 5 , inf = 2147483647 ;

int n , m , W , u , v , w , cost , ans ;
int deg[N] , weight[N] , value[N] ;
int f[N][N] , g[N][N] , answer[N][2] ;
bool vis[N] ;
vector <PII> G[N] ; queue<int> Q ;

void Top_sort(void) {
    for (int i = 1 ; i <= n ; ++ i ) 
        if (!deg[i]) Q.push(i) ; vis[1] = true ; memset(g,0x3f,sizeof g) ;
    while (Q.size()) {
        int u = Q.front() ; Q.pop() ; g[u][0] = 0 ;
        for (auto v : G[u]) {
            int son = v.first , Value_Type = v.second ;
            for (int i = W ; (~i) && vis[u] ; -- i) {
                if (f[u][i] > f[son][i]) 
                    f[son][i] = f[u][i] , g[son][i] = g[u][i] + i * Value_Type ;
                else if (f[u][i] == f[son][i]) 
                    g[son][i] = min(g[son][i],g[u][i] + i * Value_Type) ;
                if (i < weight[u]) continue ;
                if (f[u][i - weight[u]] + value[u] > f[son][i])
                    f[son][i] = f[u][i - weight[u]] + value[u] ,
                    g[son][i] = g[u][i - weight[u]] + i * Value_Type ;
                else if (f[u][i - weight[u]] + value[u] == f[son][i]) 
                    g[son][i] = min(g[son][i],g[u][i - weight[u]] + i * Value_Type) ;
            } vis[son] |= vis[u] ;
            if (!(-- deg[son])) Q.push(son) ;
        }
    } return void() ;
}

signed main(int argc,char *argv[]) {
    fre(travel) ; ios::sync_with_stdio(false) ;
    cin.tie(0) , cout.tie(0) ;
    cin >> n >> m >> W ;
    for (int i = 1 ; i <= n ; ++ i) cin >> weight[i] >> value[i] ;
    for (int i = 1 ; i <= m ; ++ i) {
        cin >> u >> v >> w ; G[u].push_back(MK(v,w)) , ++ deg[v] ;
    } Top_sort() ;
    for (int i = W ; ~i ; -- i) {
        answer[i][0] = f[n][i] ;
        answer[i][1] = g[n][i] ;
        if (i < weight[n]) continue ;
        if (f[n][i - weight[n]] + value[n] > answer[i][0])
            answer[i][0] = f[n][i - weight[n]] + value[n] ,
            answer[i][1] = g[n][i - weight[n]] ;
        else if (f[n][i - weight[n]] + value[n] == answer[i][0]) 
            answer[i][1] = min(answer[i][1],g[n][i - weight[n]]) ;
    } ans = - inf ;
    for (int i = W ; ~i ; -- i )
        if (answer[i][0] > ans)
            ans = answer[i][0] , cost = answer[i][1] ;
        else if (answer[i][0] == ans) cost = min(cost,answer[i][1]) ;
    return printf("%d %d\n",ans,cost),0 ;
}