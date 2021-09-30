/*
Author:Mukrus
Email:8950466@qq.com
Date:2021/2/4 19:28
score:10/100
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;

typedef long long LL ; 

#define re register 
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline 
#define f(i,j) for(LL i = 1 ; i <= j ; ++i )
#define R(u) for(LL i = Head[u] ; i ; i = G[i].nxt )
#define clr(x) memset(x,0,sizeof x)

inl LL read (re LL f = 0,re LL x = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch=getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x + 1 : x ;
}

static const LL N = 1e5 + 5 ;
LL n , m , tot , u , v , w , q , maxlog ;
LL Head[N] , fa[N] , dep[N] ;
LL anc[N][31] , minn[N][31] ;
bool vis[N] ;
struct Edge{
    LL fr,to,nxt,linkk ;
    void add(LL u,LL v,LL w){fr = u , to = v, nxt = Head[fr] , Head[fr] = tot , linkk = w ; }
    bool operator > (Edge a)const{return linkk > a.linkk ;}
}E[N],G[N<<1];

inl LL getf(LL u){return fa[u] == u ? fa[u] : fa[u] = getf(fa[u]) ;}
inl void Kruscal(){
    sort(E+1,E+1+tot,std::greater<Edge>()) ;
    f(i,n) fa[i] = i ;
    tot = 0 ;
    clr(Head) ;
    f(i,m){
        LL x = getf(E[i].fr) ;
        LL y = getf(E[i].to) ;
        if(x == y) continue ;
        fa[x] = y ;
        G[++tot].add(E[i].fr,E[i].to,E[i].linkk) ;
        G[++tot].add(E[i].to,E[i].fr,E[i].linkk) ;
    }return ;
}
inl void dfs(LL u){
    vis[u] = true ;
    R(u){
        LL y = G[i].to ;
        if(vis[y]) continue ;
        dep[y] = dep[u] + 1 ;
        dfs(y) ;
        anc[y][0] = u ;
        minn[y][0] = G[i].linkk ;
    }return ;
}
inl void Father(){
    f(i,maxlog){
        f(j,n){
            anc[j][i] = anc[anc[j][i-1]][i-1] ;
            minn[j][i] = std::min(minn[j][i-1],minn[anc[j][i-1]][i-1]) ;
        }
    }return ;
}
inl LL LCA(LL x,LL y){
    if(getf(x)!=getf(y)) return -1 ;
    if(dep[y]>dep[x]) swap(x,y) ;
    LL a[200],sz = 0 ;
    for(LL d = dep[x] - dep[y] , i = 1 ; d ; d >>= 1 , ++i ){
        a[++sz] = minn[x][i] ;
        x = anc[x][i] ;
    }
    sort(a+1,a+1+sz) ;
    if(x == y) return a[1] ;
    for(LL i = maxlog ; i ; --i ){
        if(anc[x][i]!=anc[y][i]){
            a[++sz] = minn[x][i] ;
            a[++sz] = minn[y][i] ;
            x = anc[x][i] ;
            y = anc[y][i] ;
        }
    }
    a[++sz] = minn[x][0] ;
    a[++sz] = minn[y][0] ;
    sort(a+1,a+1+sz,less<LL>()) ;
    return a[1] ;
}

signed main(){
	// fre();
    freopen("text.in","r",stdin) ;
	n = read() ;
    maxlog = (LL)(log(n)/log(2)+0.1) ;
    m = read() ;
    f(i,m){
        u = read() ;
        v = read() ;
        w = read() ;
        E[++tot].add(u,v,w) ;
    }
    Kruscal() ;
    f(i,n){
        if(!vis[i]){
            dep[i] = 1 ;
            dfs(i) ;
            anc[i][0] = i ;
            minn[i][0] = 1e15 ;
        }
    }
    Father() ;
    q = read() ;
    f(i,q){
        printf("%lld\n",LCA(read(),read())) ;
    }
	fclose(stdin) ;	fclose(stdout) ;
	return 0 ;
}	
/*

INPUT:
4 3
1 2 4
2 3 3
3 1 1
3
1 3
1 4
1 3

OUTPUT:
3
-1
3

*/