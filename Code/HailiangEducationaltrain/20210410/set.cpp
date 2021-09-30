#include <bits/stdc++.h>
using namespace std;
#define fre(x) freopen(#x".in","r",stdin) ;freopen(#x".out","w",stdout) ;

typedef long long LL ;
typedef int Int ;

inline int read (register int x=0,register bool f=0,register char ch=getchar()) {
    for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return f?~x+1:x;
}

inline LL readL (register LL x=0,register bool f=0,register char ch=getchar()) {
    for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return f?~x+1:x;
}

const int N = 1e4 + 5 ;
int n , m , u , v , T , ans ;
int deg[N] ;
vector <int> G[N] ;
queue<pair<int,int> > Q ;

inline void topu () {
    ans = 0 ;
    for (int i = 1 ; i <= n ; ++i ) if (!deg[i]) Q.push(make_pair(i,1)) ;
    while (Q.size()) {
        pair<int,int> top = Q.front() ; Q.pop() ;
        ans = std::max(top.second,ans) ;
        for (int i = 0 ; i < G[top.first].size() ; ++i ) {
            int v = G[top.first][i] ; --deg[v] ;
            if(!deg[v]) Q.push(make_pair(v,top.second+1)) ;
        }
    }
    printf ("%d\n",ans) ;
}

signed main(int argc,char *argv[]) {
    fre(set) ;
    for (T = read() ; T ; --T) {
         memset(deg,0,sizeof deg) ;
        for (register int i = 1 ; i <= n ; ++i ) G[i].clear() ;
        n = read() , m = read() ;
        for (register int i = 1 ; i <= m ; ++i ) 
            u = read() , v = read() , G[u].push_back(v) , ++deg[v] ;
        topu() ;
    }
    fclose(stdin) ; fclose(stdout) ; return 0 ;
}
/*
2 
4 4 
1 2 
2 4 
1 3 
3 4
4 4 
1 3 
1 4 
2 3 
2 4
*/